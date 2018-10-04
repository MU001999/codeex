#ifndef PARSER_H
#define PARSER_H

/*
stmt : decl | unary_exp
     ;

decl : type_spec init_declarator COMMA
     ;

type_spec : TVOID | TCHAR | TSHORT | TINT | TLONG | TFLOAT | TDOUBLE
          ;

init_declarator : declarator
                | declarator EQ initializer
                ;

declarator : pointer direct_declarator
           | direct_declarator
           ;

pointer : STAR pointer
        ;

direct_declarator : id
                  | LPAREN declarator RPAREN
                  | direct_declarator LBRACKET RBRACKET
                  | direct_declarator LBRACKET INTEGER RBRACKET
                  | direct_declarator LBRACKET IDENTIFIER RBRACKET
                  | direct_declarator LPAREN RPAREN
                  | direct_declarator LPAREN param_list RPAREN
                  ;

param_list : param_decl
           | param_decl COMMA param_list
           ;

param_decl : type_sepc
           ;

initializer : unary_exp
            | LBRACE initializer_list RBRACE
            ;

initializer_list : initializer COMMA initializer_list
                 | initializer
                 ;

unary_exp : primary_exp
          : unary_operator unary_exp
          ;

unary_operator : AND | STAR
               ;

primary_exp : IDENTIFIER
            | const
            | STRING
            ;

const : INTEGER
      | FLOAT
      | CHAR
      ;
*/

using STMT = ::std::shared_ptr<Stmt>;
using EXPR = ::std::shared_ptr<Expr>;

struct Parser
{
    Tokenizer tokenizer;
    ::std::vector<Token>::iterator iToken;

    STMT genStmt();
    STMT genDecl();

    EXPR genDeclarator(EXPR);
    EXPR genDirectDeclarator(EXPR);
    ::std::vector<EXPR> genParamList();
    EXPR genInitializer();
    EXPR genInitializerList();
    EXPR genUnary();
    EXPR genPrimary();
    EXPR genIdent();

    Parser() {}
    ::std::shared_ptr<Node> getNode(::std::string);
};

#endif // PARSER_H
