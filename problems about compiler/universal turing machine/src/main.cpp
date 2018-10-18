#include "UTM.h"


Machine mac;


void init(string path)
{
    ifstream fin(path);
    if (fin.bad())
    {
        cout << "cannot open file " << path << endl;
        exit(0);
    }

    string line;
    while (!fin.eof())
    {
        getline(fin, line);
        mac.init(line);
    }

    fin.close();
}


void run(string path)
{
    ifstream fin(path);
    if (fin.bad())
    {
        cout << "cannot open file " << path << endl;
        exit(0);
    }

    string line;
    getline(fin, line);
    mac.run(line);

    fin.close();
}


int main(int argc, char *argv[])
{
    Machine mac;
    string path4utm, path4type;

    if (argc > 1) path4utm = argv[1];
    else getline(cin, path4utm);
    
    if (argc > 2) path4type = argv[2];
    else getline(cin, path4type);

    init(path4utm);
    run(path4type);

    return 0;
}