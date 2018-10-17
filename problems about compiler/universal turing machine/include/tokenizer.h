#ifndef TOKENIZER_H
#define TOKENIZER_H


struct Token
{
    enum class TOKEN
    {
        END,     // $
        COLON,   // :
        COMMA,   // ,
        SEM,     // ;
        LPAREN,  // (
        RPAREN,  // )
        ARROW,   // ->

        SOI,     // [a-zA-Z0-9]+    // State or Input 

        Q,      // Q
        SIGMA,  // Sigma
        Q0,     // q0
        ACCEPT, // Accept
        REJECT, // Reject
        DELTA,  // Delta
    } token_id;

    string value;

    Token(TOKEN token_id) : token_id(token_id) {}
    Token(string value);
};


using TOKEN = Token::TOKEN;


struct Tokenizer
{
    enum class State
    {
        Begin,
        InSOI,
    };

    static vector<Token> getTokens(string);
};


#endif // TOKENIZER_H