#ifndef MACHINE_H
#define MACHINE_H

struct Machine
{
    set<string> Q;
    set<string> Sigma;
    set<string> Accept;
    set<string> Reject;
    string q0;

    string state;

    unordered_map<tuple<string, char>, tuple<string, char, char>> map4delta;
    tuple<string, char, char> Delta(string, char);

    void run(string);

    void init(string);
};

#endif // MACHINE_H