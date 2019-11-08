#include <random>
#include <vector>
#include <thread>
#include "InternetCardCommand.hpp"
#include "RamCommand.hpp"
#include "SoundCardCommand.hpp"
#include "OS.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    OS os; os.run();

    auto internetCard = make_shared<InternetCard>("icard");
    auto ram = make_shared<Ram>("ram");
    auto soundCard = make_shared<SoundCard>("scard");

    vector<shared_ptr<Command>> readCommands
    {
        make_shared<InternetCardReadCommand>(internetCard),
        make_shared<RamReadCommand>(ram),
        make_shared<SoundCardReadCommand>(soundCard)
    };

    vector<shared_ptr<Command>> writeCommands
    {
        make_shared<InternetCardWriteCommand>(internetCard),
        make_shared<RamWriteCommand>(ram),
        make_shared<SoundCardWriteCommand>(soundCard)
    };

    // https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 2);
    for (int i = 0; i < 5; ++i)
    {
        os.addReadCommand(readCommands[dis(gen)]);
        os.addWriteCommand(writeCommands[dis(gen)]);
    }

    this_thread::sleep_for(200ms);
    os.stop();

    return 0;
}
