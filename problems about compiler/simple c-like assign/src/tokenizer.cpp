#include "SCA.h"


Token::Token(string value) : value(value)
{
    if      (value == "void")   token_id = TOKEN::TVOID;
    else if (value == "char")   token_id = TOKEN::TCHAR;
    else if (value == "short")  token_id = TOKEN::TSHORT;
    else if (value == "int")    token_id = TOKEN::TINT;
    else if (value == "long")   token_id = TOKEN::TLONG;
    else if (value == "float")  token_id = TOKEN::TFLOAT;
    else if (value == "double") token_id = TOKEN::TDOUBLE;
    else                        token_id = TOKEN::IDENTIFIER;
}


void Tokenizer::analy(string line)
{
    auto state = State::Begin;
    auto reading = line.c_str();
    string value;

    while (*reading)
    {
        switch (state)
        {
        case State::Begin:
            switch (*reading)
            {
            case '$':
                tokens.push_back(Token(TOKEN::END));
                break;
            case '(':
                tokens.push_back(Token(TOKEN::LPAREN));
                break;
            case ')':
                tokens.push_back(Token(TOKEN::RPAREN));
                break;
            case '[':
                tokens.push_back(Token(TOKEN::LBRACKET));
                break;
            case ']':
                tokens.push_back(Token(TOKEN::RBRACKET));
                break;
            case '{':
                tokens.push_back(Token(TOKEN::LBRACE));
                break;
            case '}':
                tokens.push_back(Token(TOKEN::RBRACE));
                break;
            case ',':
                tokens.push_back(Token(TOKEN::COMMA));
                break;
            case '*':
                tokens.push_back(Token(TOKEN::STAR));
                break;
            case '&':
                tokens.push_back(Token(TOKEN::AND));
                break;
            case '=':
                tokens.push_back(Token(TOKEN::EQ));
                break;
            case ';':
                tokens.push_back(Token(TOKEN::SEM));
                break;
            case '"':
                state = State::InString;
                break;
            case '\'':
                state = State::InChar;
                value += *reading;
                break;
            default:
                if (isdigit(*reading))
                {
                    state = State::InInteger;
                    value += *reading;
                }
                else if (*reading == '_' || isalpha(*reading))
                {
                    state = State::InIdentifier;
                    value += *reading;
                }
                break;
            }
            break;

        case State::InInteger:
            switch (*reading)
            {
            case '.':
                value += '.';
                state = State::InDouble;
                break;
            default:
                if (isdigit(*reading))
                {
                    value += *reading;
                }
                else
                {
                    tokens.push_back(Token(TOKEN::INTEGER, value));
                    state = State::Begin;
                    value = "";
                    --reading;
                }
                break;
            }
            break;

        case State::InDouble:
            if (isdigit(*reading))
            {
                value += *reading;
            }
            else
            {
                tokens.push_back(Token(TOKEN::FLOAT, value));
                state = State::Begin;
                value = "";
                --reading;
            }
            break;

        case State::InIdentifier:
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

        case State::InString:
            switch (*reading)
            {
            case '\n': 
                printf("syntax error!\n");
                exit(0);
            case '"':
                tokens.push_back(Token(TOKEN::STRING, value));
                state = State::Begin;
                value = "";
                break;
            default:
                value += *reading;
                break;
            }
            break;

        case State::InChar:
            value += *reading;
            tokens.push_back(Token(TOKEN::CHAR, value + '\''));
            if (*(++reading) != '\'')
            {
                printf("syntax error!\n");
                exit(0);
            }
            state = State::Begin;
            value = "";
            break;
        }
        ++reading;
    }
}


vector<Token> &Tokenizer::getTokens(string line)
{
    tokens.clear();
    analy(line + "$");
    return tokens;
}