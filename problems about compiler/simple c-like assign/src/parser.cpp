#include "SCA.h"


STMT Parser::genStmt()
{
    switch (iToken->token_id)
    {
    case TOKEN::TVOID:
    case TOKEN::TCHAR:
    case TOKEN::TSHORT:
    case TOKEN::TINT:
    case TOKEN::TLONG:
    case TOKEN::TFLOAT:
    case TOKEN::TDOUBLE:
        return genDecl();
    default:
        return ::std::make_shared<ExprStmt>(genUnary());
    }
}


STMT Parser::genDecl()
{
    auto type = ::std::make_shared<TypeExpr>(iToken++->token_id);

    auto declarator = genDeclarator(type);
    EXPR initializer = nullptr;

    if (iToken++->token_id == TOKEN::EQ) initializer = genInitializer();

    return ::std::make_shared<DeclStmt>(declarator, initializer);
}


EXPR Parser::genDeclarator(EXPR type)
{
    while (iToken->token_id == TOKEN::STAR || iToken->token_id == TOKEN::AND)
    {
        if (iToken->token_id == TOKEN::STAR)
            type = ::std::make_shared<PointerExpr>(type);
        else
            type = ::std::make_shared<ReferenceExpr>(type);
        ++iToken;
    }

    return genDirectDeclarator(type);
}


EXPR Parser::genDirectDeclarator(EXPR type)
{
    EXPR id = nullptr;
    auto _iToken = iToken;
    bool f = false;
    if (iToken->token_id == TOKEN::IDENTIFIER)
    {
        id = genIdent();
    }
    else if (iToken->token_id == TOKEN::LPAREN)
    {
        _iToken = ++iToken;
        f = true;
        int n = 1;
        while (n)
        {
            if (iToken->token_id == TOKEN::LPAREN) ++n;
            else if (iToken->token_id == TOKEN::RPAREN) --n;
            ++iToken;
        }
    }

    ::std::vector<int> tail;
    ::std::vector<::std::vector<Token>::iterator> its;
    while (iToken->token_id == TOKEN::LBRACKET || iToken->token_id == TOKEN::LPAREN)
    {
        if (iToken->token_id == TOKEN::LPAREN)
        {
            ++iToken;
            its.push_back(iToken);
            tail.push_back(-(int)its.size());
            while (iToken++->token_id != TOKEN::RPAREN);
            continue;
        }
        ++iToken;
        if (iToken->token_id == TOKEN::RBRACKET)
        {
            tail.push_back(0);
            ++iToken;
            continue;
        }
        else if (iToken->token_id == TOKEN::INTEGER)
        {
            tail.push_back(stoi(iToken++->value));
            ++iToken;
            continue;
        }
        else break;
    }
    if (tail.size())
    {
        for (int i = tail.size() - 1; i >= 0; --i)
        {
            if (tail[i] > 0) type = ::std::make_shared<ArrayExpr>(tail[i], type);
            else if (tail[i] == 0) type = ::std::make_shared<ArrayExpr>(type);
            else
            {
                auto _tempi = its[-tail[i]-1];
                swap(_tempi, iToken);
                type = ::std::make_shared<FunctionExpr>(type, genParamList());
                swap(_tempi, iToken);
            }
        }
    }

    if (f)
    {
        swap(_iToken, iToken);
        type = genDeclarator(type);
        swap(_iToken, iToken);
    }

    if (id) return ::std::make_shared<VarExpr>(::std::dynamic_pointer_cast<IdentifierExpr>(id), type);
    return type;
}


::std::vector<EXPR> Parser::genParamList()
{
    ::std::vector<EXPR> res;
    while (iToken->token_id != TOKEN::RPAREN)
    {
        res.push_back(::std::make_shared<TypeExpr>(iToken++->token_id));
        if (iToken->token_id == TOKEN::COMMA) ++iToken;
    }
    return res;
}


EXPR Parser::genInitializer()
{
    EXPR initializer = nullptr;
    if (iToken->token_id == TOKEN::LBRACE)
    {
        ++iToken;
        initializer = genInitializerList();
        ++iToken;
    }
    else initializer = genUnary();
    return initializer;
}


EXPR Parser::genInitializerList()
{
    ::std::vector<EXPR> exprs;
    while (iToken->token_id != TOKEN::RPAREN)
    {
        exprs.push_back(genUnary());
        if (iToken->token_id == TOKEN::COMMA) ++iToken;
    }
    return ::std::make_shared<ListExpr>(exprs);
}


EXPR Parser::genUnary()
{
    auto op = iToken->token_id;
    switch (op)
    {
    case TOKEN::AND:
    case TOKEN::STAR:
        ++iToken;
        return ::std::make_shared<UnaryExpr>(op, genUnary());
    default:
        return genPrimary();
    }
    return nullptr;
}


EXPR Parser::genPrimary()
{
    switch (iToken->token_id)
    {
    case TOKEN::IDENTIFIER:
        return genIdent();
    case TOKEN::INTEGER:
        return ::std::make_shared<LongExpr>(stoi(iToken++->value));
    case TOKEN::FLOAT:
        return ::std::make_shared<FloatExpr>(stod(iToken++->value));
    case TOKEN::CHAR:
        return ::std::make_shared<LongExpr>(stoi(iToken++->value));
    case TOKEN::STRING:
        return ::std::make_shared<StringExpr>(iToken++->value);
    default:
        break;
    }
    return nullptr;
}


EXPR Parser::genIdent()
{
    return ::std::make_shared<IdentifierExpr>(iToken++->value);
}


::std::shared_ptr<Node> Parser::getNode(::std::string line)
{
    auto &tokens = tokenizer.getTokens(line);
    iToken = tokens.begin();
    return (iToken == tokens.end()) ? nullptr : genStmt();
}