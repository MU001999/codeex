#pragma once

#include <thread>
#include <string>
#include <iostream>
#include <shared_mutex>
#include "Device.hpp"

class Ram : public Device
{
  public:
    Ram(std::string name) : name_(std::move(name)) {}

    void read()
    {
        std::shared_lock lock(mutexForExec_);
        std::cout << name_ << " is reading..." << std::endl;
    }
    void write()
    {
        std::unique_lock lock(mutexForExec_);
        std::cout << name_ << " is writing..." << std::endl;
    }

  private:
    std::shared_mutex mutexForExec_;
    std::string name_;
};
