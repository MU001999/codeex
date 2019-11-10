#pragma once

#include <memory>

// absract class Command that provides the interface's decleration
class Command
{
  public:
    virtual ~Command() = default;
    // method execute, it will call the real method of others
    virtual void execute() = 0;
};

// helpful macro to generate Command classes for those devices
// Device : which device this macro generate class for
// Op     : which op to call when calling the method execute
// Name   : the member variable's name
// Method : the real method's name of the given device
// in the generated class
// method execute will call the real method of the given device
#define GEN_COMMAND(Device, Op, Name, Method) \
class Device##Op##Command : public Command \
{ \
  public: \
    Device##Op##Command(std::shared_ptr<Device> Name) \
      : Name##_(Name) \
    {} \
    void execute() override \
    { \
        Name##_->Method(); \
    } \
  private: \
    std::shared_ptr<Device> Name##_; \
}
