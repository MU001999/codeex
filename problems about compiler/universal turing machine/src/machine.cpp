#include <UTM.h>


tuple<string, string, string> Machine::Delta(string state, string input)
{
    return map4delta[make_tuple(state, input)];
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
                cout << "In Accept" << endl;
            }
            else if (Reject.count(state))
            {
                cout << "In Reject" << endl;
            }
            else
            {
                cout << "Not Accept or Reject" << endl;
            }
        }
        else
        {
            printf("(%s, %s)->(%s, %s, %s)\n", state.c_str(), (*reading).c_str(), get<0>(res).c_str(), get<1>(res).c_str(), get<2>(res).c_str());
            state = get<0>(res);
            auto _3 = get<2>(res);
            if (_3 == "R") ++reading;
            else if (_3 == "L") --reading;
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
        map4delta[get<0>(res)] = get<1>(res);
    }
        break;
    default:
        break;
    }
}