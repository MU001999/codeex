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

    string value;

    Token(TOKEN token_id) : token_id(token_id) {}
    Token(TOKEN token_id, string value) : token_id(token_id), value(value) {}
    Token(string value);
};


using TOKEN = Token::TOKEN;


struct Tokenizer
{
    vector<Token> tokens;

    enum class State
    {
        Begin,

        InInteger,
        InDouble,
        InIdentifier,
        InString,
        InChar,
    };

    void analy(string);

    Tokenizer() = default;

    vector<Token> &getTokens(string);
};


#endif // TOKENIZER_H
