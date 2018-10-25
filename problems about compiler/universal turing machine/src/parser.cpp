#include "UTM.h"


set<string> Parser::gen_set(vector<Token> tokens)
{
    set<string> res;

    for (auto &token : tokens)
    {
        if (token.token_id == TOKEN::SOI)
        {
            res.insert(token.value);
        }
    }

    return res;
}



tuple<tuple<string, string>, tuple<string, string, string>> Parser::gen_4delta(vector<Token> tokens)
{
    size_t base = tokens[0].token_id == TOKEN::DELTA ? 2 : 0;

#define TID(n) tokens[base + n].token_id
#define TKV(n) tokens[base + n].value

    if (tokens.size() - base == 15
        && TID(0)  == TOKEN::LPAREN
        && TID(1)  == TOKEN::SOI
        && TID(2)  == TOKEN::COMMA
        && TID(3)  == TOKEN::SOI
        && TID(4)  == TOKEN::RPAREN
        && TID(5)  == TOKEN::ARROW
        && TID(6)  == TOKEN::LPAREN
        && TID(7)  == TOKEN::SOI
        && TID(8)  == TOKEN::COMMA
        && TID(9)  == TOKEN::SOI
        && TID(10) == TOKEN::COMMA
        && TID(11) == TOKEN::SOI
        && TID(12) == TOKEN::RPAREN)
    {
        return make_tuple(make_tuple(TKV(1), TKV(3)), make_tuple(TKV(7), TKV(9), TKV(11)));
    }
    else if (tokens.size() - base == 14
        && TID(0) == TOKEN::LPAREN
        && TID(1) == TOKEN::SOI
        && TID(2) == TOKEN::COMMA
        && TID(3) == TOKEN::RPAREN
        && TID(4) == TOKEN::ARROW
        && TID(5) == TOKEN::LPAREN
        && TID(6) == TOKEN::SOI
        && TID(7) == TOKEN::COMMA
        && TID(8) == TOKEN::SOI
        && TID(9) == TOKEN::COMMA
        && TID(10) == TOKEN::SOI
        && TID(11) == TOKEN::RPAREN)
    {
        return make_tuple(make_tuple(TKV(1), " "), make_tuple(TKV(6), TKV(8), TKV(10)));
    }
    else if (tokens.size() - base == 14
        && TID(0) == TOKEN::LPAREN
        && TID(1) == TOKEN::SOI
        && TID(2) == TOKEN::COMMA
        && TID(3) == TOKEN::SOI
        && TID(4) == TOKEN::RPAREN
        && TID(5) == TOKEN::ARROW
        && TID(6) == TOKEN::LPAREN
        && TID(7) == TOKEN::SOI
        && TID(8) == TOKEN::COMMA
        && TID(9) == TOKEN::COMMA
        && TID(10) == TOKEN::SOI
        && TID(11) == TOKEN::RPAREN)
    {
        return make_tuple(make_tuple(TKV(1), TKV(3)), make_tuple(TKV(7), " ", TKV(10)));
    }
    else if (tokens.size() - base == 13
        && TID(0) == TOKEN::LPAREN
        && TID(1) == TOKEN::SOI
        && TID(2) == TOKEN::COMMA
        && TID(3) == TOKEN::RPAREN
        && TID(4) == TOKEN::ARROW
        && TID(5) == TOKEN::LPAREN
        && TID(6) == TOKEN::SOI
        && TID(7) == TOKEN::COMMA
        && TID(8) == TOKEN::COMMA
        && TID(9) == TOKEN::SOI
        && TID(10) == TOKEN::RPAREN)
    {
        return make_tuple(make_tuple(TKV(1), " "), make_tuple(TKV(6), " ", TKV(9)));
    }
    else
    {
        cout << "content of Delta should be line \"(state, chr)->(state, chr, action)\"" << endl;
        exit(0);
    }

#undef TID
#undef TKV

}


vector<string> Parser::gen_input(string line, set<string> &Sigma)
{
    vector<string> res;    
    
    auto tokens = Tokenizer::getTokens(line);

    for (auto it = tokens.cbegin(); it != tokens.cend(); ++it)
    {
        if (it->token_id == TOKEN::SOI)
        {
            if (it->value.size() != 1)
            {
                cout << "content of tape should be single character" << endl;
                exit(0);
            }
            else if (!Sigma.count(it->value))
            {
                cout << "content of tape should belong to Sigma" << endl;
                exit(0);
            }
            res.push_back(it->value);
        }
        else if (it->token_id == TOKEN::COMMA && (it + 1) != tokens.cend() && (it + 1)->token_id == TOKEN::COMMA)
        {
            res.push_back(" ");
        }
    }

    return res;
}