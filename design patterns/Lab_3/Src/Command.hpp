#pragma once

#include <memory>

class Command
{
  public:
    virtual ~Command() = default;
    virtual void execute() = 0;
};

#define GEN_COMMAND(Device, Op, Name, Function) \
class Device##Op##Command : public Command \
{ \
  public: \
    Device##Op##Command(std::shared_ptr<Device> Name) \
      : Name##_(Name) \
    {} \
    void execute() override \
    { \
        Name##_->Function(); \
    } \
  private: \
    std::shared_ptr<Device> Name##_; \
}
