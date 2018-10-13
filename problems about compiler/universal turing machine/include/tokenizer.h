#ifndef TOKENIZER_H
#define TOKENIZER_H


struct Token
{
    enum TOKEN
    {
        END,     // #
        COLON,   // :
        COMMA,   // ,
        SEM,     // ;
        LPAREN,  // (
        RPAREN,  // )
        ARROW,   // ->

        SOI,     // [a-zA-Z0-9]+    // State or Input 

        LQ,      // Q
        LSIGMA,  // Sigma
        LQ0,     // q0
        LACCEPT, // Accept
        LREJECT, // Reject
        LDELTA,  // Delta
    } token_id;

    string value;
};


#endif // TOKENIZER_H