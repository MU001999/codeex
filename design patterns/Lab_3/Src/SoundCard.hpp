#pragma once

#include <thread>
#include <string>
#include <iostream>
#include <shared_mutex>
#include "Device.hpp"

class SoundCard : public Device
{
  public:
    SoundCard(std::string name) : name_(std::move(name)) {}

    void play()
    {
        std::shared_lock lock(mutexForExec_);
        std::cout << name_ << " is playing..." << std::endl;
    }
    void record()
    {
        std::unique_lock lock(mutexForExec_);
        std::cout << name_ << " is recording..." << std::endl;
    }

  private:
    std::shared_mutex mutexForExec_;
    std::string name_;
};
