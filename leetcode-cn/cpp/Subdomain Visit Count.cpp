/*
Q-URL: https://leetcode-cn.com/problems/subdomain-visit-count
*/

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, unsigned long long> cnts;
        for (auto &cpdomain : cpdomains)
        {
            auto cnt = stoull(cpdomain.substr(0, cpdomain.find(' ')));
            auto domain = cpdomain.substr(cpdomain.find(' '));
            for (size_t pos = 0, end_pos; pos != domain.npos; pos = domain.find('.', pos + 1))
            {
                cnts[domain.substr(pos + 1)] += cnt;
            }
        }
        
        vector<string> res;
        for (auto &domain_cnt : cnts)
        {
            res.push_back(to_string(domain_cnt.second) + " " + domain_cnt.first); 
        }
        return res;
    }
};
