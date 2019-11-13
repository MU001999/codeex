#pragma once

#include <thread>
#include <string>
#include <iostream>
#include <shared_mutex>
#include "Device.hpp"

// concrete class SoundCard extends class Device
class SoundCard : public Device
{
  public:
    // constructor, just receive the name of this card
    SoundCard(std::string name) : name_(std::move(name)) {}

    // method play, it will just print the helpful info simply
    void play()
    {
        // locks the associated shared mutex in shared mode
        std::shared_lock lock(mutexForExec_);
        std::cout << name_ << " is playing..." << std::endl;
    }
    // method record, it will just print the helpful info simply
    void record()
    {
        // locks the associated shared mutex in exclusive mode
        std::unique_lock lock(mutexForExec_);
        std::cout << name_ << " is recording..." << std::endl;
    }

  private:
    // the shared mutex to make sure that method sendIn will block
    // when method recvFrom is calling
    std::shared_mutex mutexForExec_;
    std::string name_;
};
