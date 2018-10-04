#ifndef TOKENIZER_H
#define TOKENIZER_H

struct Token
{
    enum class TOKEN
    {
        END,        // $

        TVOID,      // void
        TCHAR,      // char
        TSHORT,     // short
        TINT,       // int
        TLONG,      // long
        TFLOAT,     // float
        TDOUBLE,    // double

        IDENTIFIER, // [a-zA-Z_]+[a-zA-Z0-9_]*
        INTEGER,    // [0-9]+
        FLOAT,      // [0-9]+\.[0-9]*
        STRING,     // "[^"\n]"
        CHAR,       // '[a-zA-Z1-9_]'

        LPAREN,     // (
        RPAREN,     // )
        LBRACKET,   // [
        RBRACKET,   // ]
        LBRACE,     // {
        RBRACE,     // }

        COMMA,      // ,
        STAR,       // *
        AND,        // &
        EQ,         // =
        SEM,        // ;
    } token_id;

    ::std::string value;

    Token(TOKEN token_id) : token_id(token_id) {}
    Token(TOKEN token_id, ::std::string value) : token_id(token_id), value(value) {}
    Token(::std::string value);
};

using TOKEN = Token::TOKEN;

struct Tokenizer
{
    ::std::vector<Token> tokens;

    enum class State
    {
        Begin,

        InInteger,
        InDouble,
        InIdentifier,
        InString,
        InChar,
    };

    void analy(::std::string);

    Tokenizer() {}

    ::std::vector<Token> &getTokens(::std::string);
};


#endif // TOKENIZER_H
