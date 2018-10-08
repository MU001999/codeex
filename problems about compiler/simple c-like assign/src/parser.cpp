#include "SCA.h"


static string _cal(TOKEN op, string value)
{
    if (op == TOKEN::AND)
    {
        if (isdigit(value[0]))
        {
            cout << "After & should be the variable name" << endl;
            return "";
        }
        else
        {
            return to_string(symtable.get_addr(value));
        }
    }
    else
    {
        if (isdigit(value[0]))
        {
            return symtable.get_name(stoi(value));
        }
        else
        {
            return symtable.get_name(symtable.get_addr(value));
        }
    }
}


string Parser::genStmt()
{
    switch (iToken->token_id)
    {
    case TOKEN::TVOID:
        value.size = 0;
        return genDecl();

    case TOKEN::TCHAR:
        value.size = 1;
        return genDecl();

    case TOKEN::TSHORT:
        value.size = 2;
        return genDecl();

    case TOKEN::TINT:
    case TOKEN::TFLOAT:
        value.size = 4;
        return genDecl();

    case TOKEN::TLONG:
    case TOKEN::TDOUBLE:
        value.size = 8;
        return genDecl();

    case TOKEN::IDENTIFIER:
        identifier = genIdent();
        if (iToken++->token_id == TOKEN::EQ)
        {
            value.val = genUnary();
        }
        else
        {
            value.val = identifier;
            identifier = "";
        }
        return "";

    default:
        value.val = genUnary();
        return "";
    }
}


string Parser::genDecl()
{
    auto declarator = genDeclarator(iToken++->value);

    if (iToken++->token_id == TOKEN::EQ)
    {
        value.val = genInitializer();
    }

    return declarator;
}


string Parser::genDeclarator(string type)
{
    while (iToken->token_id == TOKEN::STAR || iToken->token_id == TOKEN::AND)
    {
        type = ((iToken->token_id == TOKEN::STAR) ? "Pointer_" : "Rreference_") + type;
        value.size = (iToken++->token_id == TOKEN::STAR) ? 4 : value.size;
    }
    return genDirectDeclarator(type);
}


string Parser::genDirectDeclarator(string type)
{
    auto _iToken = iToken;
    bool need_backtrack = false;


    if (iToken->token_id == TOKEN::IDENTIFIER)
    {
        identifier = genIdent();
    }
    else if (iToken->token_id == TOKEN::LPAREN)
    {
        _iToken = ++iToken;
        need_backtrack = true;

        int n = 1;
        while (n)
        {
            if (iToken->token_id == TOKEN::LPAREN)
            {
                ++n;
            }
            else if (iToken->token_id == TOKEN::RPAREN)
            {
                --n;
            }
            ++iToken;
        }
    }


    vector<int> counts;
    vector<vector<Token>::iterator> its4backtrack;

    while (iToken->token_id == TOKEN::LBRACKET || iToken->token_id == TOKEN::LPAREN)
    {
        if (iToken->token_id == TOKEN::LPAREN)
        {
            ++iToken;
            its4backtrack.push_back(iToken);
            counts.push_back(-(int)its4backtrack.size());
            while (iToken++->token_id != TOKEN::RPAREN);
            continue;
        }

        ++iToken;
        if (iToken->token_id == TOKEN::RBRACKET)
        {
            counts.push_back(0);
            ++iToken;
            continue;
        }
        else if (iToken->token_id == TOKEN::INTEGER)
        {
            counts.push_back(stoi(iToken++->value));
            ++iToken;
            continue;
        }
        else break;
    }

    if (counts.size())
    {
        for (int i = counts.size() - 1; i >= 0; --i)
        {
            if (counts[i] > 0)
            {
                value.size *= counts[i];
                type = "Array" + to_string(counts[i]) + "_" + type;
            }
            else if (counts[i] == 0)
            {
                 type = "Array_" + type;
            }
            else
            {
                value.size = line.size();
                auto _tempi = its4backtrack[-counts[i]-1];
                swap(_tempi, iToken);
                type = "Function(" + type + ", " + genParamList() + ")";
                swap(_tempi, iToken);
            }
        }
    }


    if (need_backtrack)
    {
        swap(_iToken, iToken);
        type = genDeclarator(type);
        swap(_iToken, iToken);
    }


    return type;
}


string Parser::genParamList()
{
    string res;
    while (iToken->token_id != TOKEN::RPAREN)
    {
        if (res.size())
        {
            res += ", ";
        }
        res += iToken++->value;
        if (iToken->token_id == TOKEN::COMMA)
        {
            ++iToken;
        }
    }
    return res;
}


string Parser::genInitializer()
{
    if (iToken->token_id == TOKEN::LBRACE)
    {
        ++iToken;
        return genInitializerList();
    }
    else
    {
        return genUnary();
    }
}


string Parser::genInitializerList()
{
    // value.val += "{";
    while (iToken->token_id != TOKEN::RBRACE)
    {
        value.val += genUnary() + " ";
        if (iToken->token_id == TOKEN::COMMA)
        {
            ++iToken;
        }
    }
    ++iToken;
    // value.val += "}";
    return value.val;
}


string Parser::genUnary()
{
    auto op = iToken->token_id;
    switch (op)
    {
    case TOKEN::AND:
    case TOKEN::STAR:
        ++iToken;
        return _cal(op, genUnary());
    default:
        return iToken++->value;
    }
}


string Parser::genIdent()
{
    return iToken++->value;
}


string Parser::parse(string line)
{
    this->line = line;
    auto &tokens = tokenizer.getTokens(line);
    iToken = tokens.begin();
    auto res = (iToken == tokens.end()) ? "" : genStmt();
    if (res[0] == 'F')
    {
        value = Value{ (int)line.size(), line };
        return "Function: " + line;
    }
    else
    {
        return res;
    }
}