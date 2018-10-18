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

    unordered_map<tuple<string, string>, tuple<string, string, string>> map4delta;
    tuple<string, string, string> Delta(string, string);

    void run(string);

    void init(string);
};

#endif // MACHINE_H