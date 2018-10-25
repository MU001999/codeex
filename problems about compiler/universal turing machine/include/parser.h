#ifndef PARSER_H
#define PARSER_H


struct Parser
{
    static set<string> gen_set(vector<Token>);
    
    static tuple<tuple<string, string>, tuple<string, string, string>> gen_4delta(vector<Token>);

    static vector<string> gen_input(string, set<string>&);
};


#endif // PARSER_H