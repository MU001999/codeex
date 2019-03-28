#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#include <cstring>

#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>


class Response
{
private:

    int           p_status_code = 400;
    ::std::string p_raw, p_reason, p_body;

    ::std::unordered_map<::std::string, ::std::string> p_headers;

public:

    Response() {}

    Response(const ::std::string &data) : p_raw(data)
    {
        if (data.empty()) return;

        ::std::stringstream ss(data);
        ss >> p_reason; ss >> p_status_code; ss.get();
        ::std::getline(ss, p_reason); p_reason.pop_back();

        auto header_endpos = data.find("\r\n\r\n") + 4,
                html_beginpos = data.find("<html>");

        p_body = html_beginpos == data.npos
                ? data.substr(header_endpos)
                : data.substr(html_beginpos);

        ::std::string tmp;
        while (::std::getline(ss, tmp) && tmp != "\r")
        {
            tmp.pop_back();
            auto pos = tmp.find(':');
            if (pos != tmp.npos)
            {
                auto k = tmp.substr(0, pos),
                        v = tmp.substr(pos + 2);
                p_headers[k] += v;
            }
        }
    }

    Response(Response &&res) noexcept = default;

    ~Response() = default;


    Response& operator=(Response &rhs)
    {
        p_status_code = rhs.p_status_code;
        p_raw         = rhs.p_raw;
        p_reason      = rhs.p_reason;
        p_body        = rhs.p_body;
        p_headers     = rhs.p_headers;

        return *this;
    }

    Response& operator=(Response &&rhs) noexcept
    {
        ::std::swap(p_status_code, rhs.p_status_code);
        ::std::swap(p_raw,         rhs.p_raw);
        ::std::swap(p_reason,      rhs.p_reason);
        ::std::swap(p_body,        rhs.p_body);
        ::std::swap(p_headers,     rhs.p_headers);

        return *this;
    }


    const int status_code() const
    {
        return p_status_code;
    }

    const ::std::string& raw() const
    {
        return p_raw;
    }

    const ::std::string& reason() const
    {
        return p_reason;
    }

    const ::std::string& body() const
    {
        return p_body;
    }

    const decltype(p_headers)& headers() const
    {
        return p_headers;
    }

};


class Request
{
private:

    static ::std::string gen_host(::std::string url)
    {
        auto pos = url.find("://");
        if (pos != url.npos) url = url.substr(pos + 3);

        pos = url.find("/");
        return pos == url.npos
                ? url
                : url.substr(0, pos);
    }

    static ::std::string gen_req(::std::string url)
    {
        auto pos = url.find("://");
        if (pos != url.npos) url = url.substr(pos + 3);

        pos = url.find('/');
        return pos == url.npos
                ? "/"
                : url.substr(pos);
    }

    static Response request(
        const ::std::string &url,
        const ::std::string &method,
        const ::std::unordered_map<::std::string, ::std::string> &headers,
        const ::std::string &payload = "")
    {
        ::std::string response_msg;


        // init server addrinfo
        addrinfo hints, *result;
        hints.ai_flags    = AI_CANONNAME;
        hints.ai_family   = AF_INET;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_protocol = IPPROTO_TCP;
        getaddrinfo(gen_host(url).c_str(), "80", &hints, &result);


        // connect to server
        auto socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        for (auto addr = result; addr != NULL; addr = addr->ai_next)
        {
            if (connect(socket_fd, addr->ai_addr, addr->ai_addrlen) == 0)
            {
                break;
            }
        }


        // init request message
        ::std::string request_msg = method + gen_req(url) + " HTTP/1.1\r\n";

        for (auto &kv : headers) request_msg += kv.first + ": " + kv.second + "\r\n";

        request_msg += "\r\n" + payload;


        // send request message to server
        if (send(socket_fd, request_msg.c_str(), request_msg.length(), 0) < 0)
            return Response();


        // receive response message from server
        char tmp[4096] = { 0 };

        while (recv(socket_fd, tmp, 4096, 0) > 0)
        {
            response_msg += tmp;
            memset(tmp, 0, sizeof(tmp));
        }

        close(socket_fd);
        freeaddrinfo(result);

        return Response(response_msg);
    }

public:

    static Response get(
        const ::std::string &url,
        const ::std::vector<::std::pair<::std::string, ::std::string>> &params = {},
        const ::std::unordered_map<::std::string, ::std::string> &headers = {})
    {
        ::std::unordered_map<::std::string, ::std::string> hds = {
            {"Host", gen_host(url)},
            {"Content-type", "text/html"},
            {"Connection", "Close"},
            {"Accept-Language", "zh-CN,zh,en-US"},
            {"User-Agent", "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:63.0) Gecko/20100101 Firefox/63.0"},
        };
        for (auto &kv : headers) hds[kv.first] = kv.second;

        ::std::string afterurl;
        if (!params.empty())
        {
            afterurl += '?';
            for (auto it = params.cbegin(); it != params.cend(); ++it)
            {
                afterurl += (it == params.cbegin() ? "" : "&") + it->first + "=" + it->second;
            }
        }

        return request(url + afterurl, "GET ", hds);
    }

    static Response get(
        const ::std::string &url,
        const ::std::unordered_map<::std::string, ::std::string> &headers)
    {
        return get(url, {}, headers);
    }
};


int main()
{
    std::cout << Request::get("http://www.bjfu.edu.cn/").raw() << std::endl;
    return 0;
}