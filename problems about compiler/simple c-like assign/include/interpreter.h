#ifndef INTERPRETER_H
#define INTERPRETER_H


struct Interpreter
{
    ::std::shared_ptr<Env> top;

    Parser parser;

    void run();

    Interpreter() : top(::std::make_shared<Env>()) {}
};


#endif // INTERPRETER_H
