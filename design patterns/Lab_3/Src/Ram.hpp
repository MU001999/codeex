#pragma once

#include <thread>
#include <string>
#include <iostream>
#include <shared_mutex>
#include "Device.hpp"

// concrete class Ram extends class Device
class Ram : public Device
{
  public:
    // constructor, just receive the name of this ram
    Ram(std::string name) : name_(std::move(name)) {}

    // method read, it will just print the helpful info simply
    void read()
    {
        // locks the associated shared mutex in shared mode
        std::shared_lock lock(mutexForExec_);
        std::cout << name_ << " is reading..." << std::endl;
    }
    // method write, it will just print the helpful info simply
    void write()
    {
        // locks the associated shared mutex in exclusive mode
        std::unique_lock lock(mutexForExec_);
        std::cout << name_ << " is writing..." << std::endl;
    }

  private:
    // the shared mutex to make sure that method sendIn will block
    // when method recvFrom is calling
    std::shared_mutex mutexForExec_;
    std::string name_;
};
