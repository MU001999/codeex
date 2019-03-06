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
            RPAREN,

            END
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

        NumberNode(int) : value(value) {}

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
            return std::make_shared<NumberNode>(std::stoi(iToken++->value));
        }

        std::shared_ptr<Node> gen_term()
        {
            if (iToken->token_id == TOKEN::LPAREN)
            {
                ++iToken;
                auto node = gen_expr();
                if (iToken->token_id != TOKEN::RPAREN) return nullptr;
                ++iToken;
                return node;
            }
            else if (iToken->token_id == TOKEN::INTEGER) return gen_number();
            else return nullptr;
        }

        std::shared_ptr<Node> gen_term_rest(std::shared_ptr<Node> lhs)
        {
            auto node = lhs;
            TOKEN op;
            switch (iToken->token_id)
            {
                case TOKEN::MUL:
                case TOKEN::DIV:
                case TOKEN::MOD:
                    op = iToken++->token_id;
                    break;
                default:
                    return node;
            }
            return gen_term_rest(std::make_shared<BinaryOperatorNode>(lhs, op, gen_term()));
        }

        std::shared_ptr<Node> gen_factor()
        {
            return gen_term_rest(gen_term());
        }

        std::shared_ptr<Node> gen_factor_rest(std::shared_ptr<Node> lhs)
        {
            auto node = lhs;
            TOKEN op;
            switch (iToken->token_id)
            {
                case TOKEN::ADD:
                case TOKEN::SUB:
                    op = iToken++->token_id;
                    break;
                default:
                    return node;
            }
            return gen_factor_rest(std::make_shared<BinaryOperatorNode>(lhs, op, gen_factor()));
        }

        std::shared_ptr<Node> gen_expr()
        {
            return gen_factor_rest(gen_factor());
        }


        decltype(auto) parse(const std::string &expr)
        {
            tokens = tokenizer(expr);
            iToken = tokens.begin();
            return gen_expr();
        }
    };
}


inline std::string calculate(const std::string &expr)
{
    return expr;
    // return std::to_string(detail::Parser().parse(expr)->run_code());
}
