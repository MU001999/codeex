#include "UTM.h"


Token::Token(string value) : value(value)
{
    if      (value == "Q")      token_id = TOKEN::Q;
    else if (value == "Sigma")  token_id = TOKEN::SIGMA;
    else if (value == "q0")     token_id = TOKEN::Q0;
    else if (value == "Accept") token_id = TOKEN::ACCEPT;
    else if (value == "Reject") token_id = TOKEN::REJECT;
    else if (value == "Delta")  token_id = TOKEN::DELTA;
    else                        token_id = TOKEN::SOI;
}


vector<Token> Tokenizer::getTokens(string line)
{
    vector<Token> tokens;
    line += '$';

    return tokens;
}