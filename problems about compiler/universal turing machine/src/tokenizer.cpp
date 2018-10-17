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

    auto state = State::Begin;
    auto reading = line.c_str();
    string value;

    while (*reading)
    {
        switch (state)
        {
        case Tokenizer::State::Begin:
            switch (*reading)
            {
            case '$':
                tokens.push_back(Token(TOKEN::END));
                break;
            case ':':
                tokens.push_back(Token(TOKEN::COLON));
                break;
            case ',':
                tokens.push_back(Token(TOKEN::COMMA));
                break;
            case ';':
                tokens.push_back(Token(TOKEN::SEM));
                break;
            case '(':
                tokens.push_back(Token(TOKEN::LPAREN));
                break;
            case ')':
                tokens.push_back(Token(TOKEN::RPAREN));
                break;
            case '-':
                if (*(reading + 1) == '>')
                {
                    tokens.push_back(Token(TOKEN::ARROW));
                    ++reading;
                }
                else
                {
                    tokens.push_back(Token("-"));
                }
                break;
            default:
                if (*reading == '_' || isalnum(*reading))
                {
                    state = State::InSOI;
                    value += *reading;
                }
                break;
            }
            break;
        case Tokenizer::State::InSOI:
            if (*reading == '_' || isalnum(*reading))
            {
                value += *reading;
            }
            else
            {
                tokens.push_back(Token(value));
                state = State::Begin;
                value = "";
                --reading;
            }
            break;
        }
        ++reading;
    }

    return tokens;
}