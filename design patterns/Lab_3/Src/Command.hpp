#pragma once

#include <random>
#include <memory>
#include <thread>

// absract class Command that provides the interface's decleration
class Command
{
  public:
    virtual ~Command() = default;
    // method execute, it will call the real method of others
    virtual void execute() = 0;

    // just sleep for random from 0ms to 10ms
    static void sleepRandom()
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        // https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
        static std::uniform_real_distribution<double> disReal(0, 1);
        using namespace std::literals::chrono_literals;
        std::this_thread::sleep_for(10ms * disReal(gen));
    }
};

// absrtact class for command of reading
class ReadCommand  : public Command
{
  public:
    virtual ~ReadCommand() = default;
    virtual void execute() = 0;
};

// abstract class for command of writing
class WriteCommand : public Command
{
  public:
    virtual ~WriteCommand() = default;
    virtual void execute() = 0;
};

// helpful macro to generate concrete Command classes for those devices
// Device : which device this macro generate class for
// Op     : which op to call when calling the method execute
// Name   : the member variable's name
// Method : the real method's name of the given device
// ---
// in the generated class, after a random (0ms ~ 10ms) sleep,
// method execute will call the real method of the given device
#define GEN_COMMAND(Device, Op, Name, Method) \
class Device##Op##Command final : public Op##Command \
{ \
  public: \
    Device##Op##Command(std::shared_ptr<Device> Name) \
      : Name##_(Name) \
    {} \
    void execute() override \
    { \
        Command::sleepRandom(); \
        Name##_->Method(); \
    } \
  private: \
    std::shared_ptr<Device> Name##_; \
}
