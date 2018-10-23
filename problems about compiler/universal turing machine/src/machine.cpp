#include <UTM.h>


tuple<string, string, string> Machine::Delta(string state, string input)
{
    return (map4delta.count(state) && map4delta[state].count(input)) ? map4delta[state][input] : make_tuple("", "", "");
}


void Machine::run(string line)
{
    auto inputs = Parser::gen_input(line);
    auto reading = inputs.begin();

    while (reading != inputs.end()) 
    {
        auto res = Delta(state, *reading);
        if (get<2>(res) == "")
        {
            if (Accept.count(state))
            {
                cout << "end with Accept-State " << state << endl;
            }
            else if (Reject.count(state))
            {
                cout << "end with Reject-State " << state << endl;
            }
            else
            {
                cout << "end with error" << endl;
            }

            cout << "content of tape will be: ";
            for (auto it = inputs.begin(); it != inputs.end(); ++it)
            {
                cout << ((it != inputs.begin()) ? "," + *it : *it);
            }
            cout << ";" << endl;
            return;
        }
        else
        {
            printf("(%s, %s) -> (%s, %s, %s)\n", state.c_str(), (*reading).c_str(), get<0>(res).c_str(), get<1>(res).c_str(), get<2>(res).c_str());

            state = get<0>(res);
            *reading = get<1>(res);
            auto _3 = get<2>(res);
            if (_3 == "R") ++reading;
            else if (_3 == "L") --reading;
        }
    }
}


void Machine::check()
{
    for (auto &s : Sigma)
    {
        if (s.size() != 1)
        {
            cout << "element of Sigma shoule be single character" << endl;
            exit(0);
        }
    }

    for (auto &s : Accept)
    {
        if (Q.count(s) == 0)
        {
            cout << "Accept should be a subset of Q" << endl;
            exit(0);
        }
        if (Reject.count(s))
        {
            cout << "Accept and Reject should be disjoint" << endl;
            exit(0);
        }
    }

    for (auto &s : Reject)
    {
        if (Q.count(s) == 0)
        {
            cout << "Reject should be a subset of Q" << endl;
            exit(0);
        }
    }

    if (Q.count(q0) == 0)
    {
        cout << "q0 should belong to Q" << endl;
        exit(0);
    }

    for (auto it : map4delta)
    {
        if (Q.count(it.first) == 0)
        {
            cout << "The states described by Delta should belong to Q" << endl;
            exit(0);
        }
        else
        {
            for (auto sit : map4delta[it.first])
            {
                if (Q.count(get<0>(sit.second)) == 0)
                {
                    cout << "The states described by Delta should belong to Q" << endl;
                    exit(0);
                }
            }
        }
    }
}


void Machine::init(string line)
{
    if (line.empty()) return;

    auto tokens = Tokenizer::getTokens(line);
    auto ftk = tokens[0];

    switch (ftk.token_id)
    {
    case TOKEN::Q:
        Q = Parser::gen_set(tokens);
        break;
    case TOKEN::SIGMA:
        Sigma = Parser::gen_set(tokens);
        break;
    case TOKEN::Q0:
        q0 = *(Parser::gen_set(tokens).begin());
        state = q0;
        break;
    case TOKEN::ACCEPT:
        Accept = Parser::gen_set(tokens);
        break;
    case TOKEN::REJECT:
        Reject = Parser::gen_set(tokens);
        break;
    case TOKEN::DELTA:
    case TOKEN::LPAREN:
    {
        auto res = Parser::gen_4delta(tokens);
        auto first = get<0>(res);
        map4delta[get<0>(first)][get<1>(first)] = get<1>(res);
    }
        break;
    default:
        break;
    }
}