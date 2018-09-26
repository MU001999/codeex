#ifndef TOKENIZER_H
#define TOKENIZER_H

struct Token
{
    enum class TOKEN
    {
        IDENTIFIER, // [a-zA-Z_]+[a-zA-Z0-9_]*
        
        INTEGER,    // [0-9]+
        FLOAT,      // [0-9]+\.[0-9]*

        LPAREN,     // (
        RPAREN,     // )
        LBRACKET,   // [
        RBRACKET,   // ]

        COMMA,      // ,
        STAR,       // *
        ET,         // &

    } token_id;
};

#endif // TOKENIZER_H
