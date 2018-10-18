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
    ptrdiff_t base = tokens[0].token_id == TOKEN::DELTA ? 2 : 0;

#define TID(n) tokens[base + n].token_id
#define TKV(n) tokens[base + n].value

    if (tokens.size() - base == 14
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
    else
    {
        cout << "content of Delta should be line \"(state, chr)->(state, chr, action)\"";
        exit(0);
    }

#undef TID(n)
#undef TKV(n)

}


vector<string> Parser::gen_input(string line)
{
    vector<string> res;    
    
    auto tokens = Tokenizer::getTokens(line);

    for (auto &token : tokens)
    {
        if (token.token_id == TOKEN::SOI)
        {
            res.push_back(token.value);
        }
    }

    return res;
}