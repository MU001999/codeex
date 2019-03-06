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

    using TOKEN = Token::TOKEN;


    struct Node
    {
        virtual ~Node() {}
        virtual int run_code() = 0;
    };

    struct NumberNode : Node
    {
        int value;

        NumberNode(std::string value) : value(stoi(value)) {}

        virtual int run_code()
        {
            return value;
        }
    };

    struct BinaryOperatorNode : Node
    {
        std::shared_ptr<Node> lhs, rhs;
        TOKEN op;

        BinaryOperatorNode(std::shared_ptr<Node> lhs, TOKEN op, std::shared_ptr<Node> rhs) :
            lhs(lhs), rhs(rhs), op(op) {}

        virtual int run_code()
        {
            switch (op)
            {
                case TOKEN::ADD:
                    return lhs->run_code() + rhs->run_code();
                case TOKEN::SUB:
                    return lhs->run_code() - rhs->run_code();
                case TOKEN::MUL:
                    return lhs->run_code() * rhs->run_code();
                case TOKEN::DIV:
                    return lhs->run_code() / rhs->run_code();
                case TOKEN::MOD:
                    return lhs->run_code() % rhs->run_code();
                default: break;
            }
            exit(0);
        }
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
