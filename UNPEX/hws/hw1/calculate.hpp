#include <string>
#include <memory>
#include <vector>
#include <iterator>


namespace detail
{
    struct Token
    {
        enum class TOKEN
        {
            INTEGER,

            ADD,
            SUB,
            MUL,
            DIV,
            MOD,

            LPAREN,
            RPAREN
        } token_id;
        std::string value;

        Token(TOKEN token_id) : token_id(token_id) {}
        Token(std::string value) : token_id(TOKEN::INTEGER), value(value) {}
    };


    struct Node
    {

    };

    struct NumberNode : Node
    {

    };

    struct BinaryOperatorNode : Node
    {

    };


    inline decltype(auto) tokenizer(const std::string &expr)
    {
        std::vector<Token> res;

        auto reading = expr.c_str();

        while (*reading)
        {

        }

        return res;
    }

    struct Parser
    {
        std::vector<Token> tokens;
        decltype(tokens)::iterator iToken;

        std::shared_ptr<Node> gen_number()
        {

        }

        std::shared_ptr<Node> gen_term()
        {

        }

        std::shared_ptr<Node> gen_factor()
        {

        }

        std::shared_ptr<Node> gen_expr()
        {

        }

        decltype(auto) parse(const std::string &expr)
        {
            tokens = tokenizer(expr);
            return gen_expr();
        }
    };
}


inline std::string calculate(const std::string &expr)
{

}
