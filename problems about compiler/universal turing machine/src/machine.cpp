#include <UTM.h>


tuple<string, char, char> Machine::Delta(string s, char c)
{
    return map4delta[make_tuple(s, c)];
}


void Machine::run(string line)
{
    line = Parser::gen_input(line);
    
    auto reading = line.c_str();

    while (*reading)
    {
        auto res = Delta(state, *reading);
        if (get<2>(res) == 0)
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
            printf("(%s, %c)->(%s, %c, %c)", state.c_str(), *reading, get<0>(res).c_str(), get<1>(res), get<2>(res));
            state = get<0>(res);
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