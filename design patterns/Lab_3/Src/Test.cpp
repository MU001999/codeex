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
    // just run the os
    OS os; os.run();

    // init three devices
    auto internetCard = make_shared<InternetCard>("icard");
    auto ram = make_shared<Ram>("ram");
    auto soundCard = make_shared<SoundCard>("scard");

    // init three read commands for above three devices
    vector<shared_ptr<ReadCommand>> readCommands
    {
        make_shared<InternetCardReadCommand>(internetCard),
        make_shared<RamReadCommand>(ram),
        make_shared<SoundCardReadCommand>(soundCard)
    };

    // init three write commands for above three devices
    vector<shared_ptr<WriteCommand>> writeCommands
    {
        make_shared<InternetCardWriteCommand>(internetCard),
        make_shared<RamWriteCommand>(ram),
        make_shared<SoundCardWriteCommand>(soundCard)
    };

    random_device rd;
    mt19937 gen(rd());
    // https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
    uniform_int_distribution<> disInt(0, 2);
    // loop for 5 times
    // and there is will be a random sleep before add operation
    for (int i = 0; i < 5; ++i)
    {
        Command::sleepRandom();
        os.addReadCommand(readCommands[disInt(gen)]);
        Command::sleepRandom();
        os.addWriteCommand(writeCommands[disInt(gen)]);
    }

    // wait for no command to execute
    this_thread::sleep_for(1s);
    // stop the os
    os.stop();

    return 0;
}
