#ifndef NODE_H
#define NODE_H


struct Node
{
    virtual ~Node() {}
    virtual ::std::shared_ptr<Object> run(::std::shared_ptr<Env>&) = 0;
};


struct Stmt : Node {};
struct Expr : Node {};


struct LongExpr : Expr
{
    long value;

    LongExpr(long value) : value(value) {}

    virtual ::std::shared_ptr<Object> run(::std::shared_ptr<Env>&);
};


struct FloatExpr : Expr
{
    double value;

    FloatExpr(double value) : value(value) {}

    virtual ::std::shared_ptr<Object> run(::std::shared_ptr<Env>&);
};


struct StringExpr : Expr
{
    ::std::string value;

    StringExpr(::std::string value) : value(value) {}

    virtual ::std::shared_ptr<Object> run(::std::shared_ptr<Env>&);
};


struct IdentifierExpr : Expr
{
    ::std::string name;

    IdentifierExpr(::std::string name) : name(name) {}

    virtual ::std::shared_ptr<Object> run(::std::shared_ptr<Env>&);
};


struct VarExpr : Expr
{
    ::std::shared_ptr<IdentifierExpr> name;
    ::std::shared_ptr<Expr> type;

    VarExpr(::std::shared_ptr<IdentifierExpr> name, ::std::shared_ptr<Expr> type) : name(name), type(type) {}

    virtual ::std::shared_ptr<Object> run(::std::shared_ptr<Env>&);
};


struct UnaryExpr : Expr
{
    TOKEN op;
    ::std::shared_ptr<Expr> expression;

    UnaryExpr(TOKEN op, ::std::shared_ptr<Expr> expression) : op(op), expression(expression) {}

    virtual ::std::shared_ptr<Object> run(::std::shared_ptr<Env>&);
};


struct ListExpr : Expr
{
    ::std::vector<::std::shared_ptr<Expr>> expressions;

    ListExpr(::std::vector<::std::shared_ptr<Expr>> expressions) : expressions(expressions) {}

    virtual ::std::shared_ptr<Object> run(::std::shared_ptr<Env>&);
};


struct TypeExpr : Expr
{
    TOKEN type;

    TypeExpr(TOKEN type) : type(type) {}

    virtual ::std::shared_ptr<Object> run(::std::shared_ptr<Env>&);
};


struct PointerExpr : Expr
{
    ::std::shared_ptr<Expr> type;

    PointerExpr(::std::shared_ptr<Expr> type) : type(type) {}

    virtual ::std::shared_ptr<Object> run(::std::shared_ptr<Env>&);
};


struct ReferenceExpr : Expr
{
    ::std::shared_ptr<Expr> type;

    ReferenceExpr(::std::shared_ptr<Expr> type) : type(type) {}

    virtual ::std::shared_ptr<Object> run(::std::shared_ptr<Env>&);
};


struct ArrayExpr : Expr
{
    int n;
    ::std::shared_ptr<Expr> type;

    ArrayExpr(::std::shared_ptr<Expr> type) : n(-1), type(type) {}
    ArrayExpr(int n, ::std::shared_ptr<Expr> type) : n(n), type(type) {}

    virtual ::std::shared_ptr<Object> run(::std::shared_ptr<Env>&);
};


struct FunctionExpr : Expr
{
    ::std::shared_ptr<Expr> return_type;
    ::std::vector<::std::shared_ptr<Expr>> param_types;

    FunctionExpr(::std::shared_ptr<Expr> return_type, ::std::vector<::std::shared_ptr<Expr>> param_types) : return_type(return_type), param_types(param_types) {}

    virtual ::std::shared_ptr<Object> run(::std::shared_ptr<Env>&);

};


struct ExprStmt : Stmt
{
    ::std::shared_ptr<Expr> expression;

    ExprStmt(::std::shared_ptr<Expr> expression) : expression(expression) {}

    virtual ::std::shared_ptr<Object> run(::std::shared_ptr<Env>&);
};


struct DeclStmt : Stmt
{
    ::std::shared_ptr<Expr> declarator;
    ::std::shared_ptr<Expr> initializer;

    DeclStmt(::std::shared_ptr<Expr> declarator, ::std::shared_ptr<Expr> initializer) : declarator(declarator), initializer(initializer) {}

    virtual ::std::shared_ptr<Object> run(::std::shared_ptr<Env>&);
};


#endif // NODE_H