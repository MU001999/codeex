#pragma once

#include <thread>
#include <string>
#include <iostream>
#include <shared_mutex>
#include "Device.hpp"

// concrete class InternetCard extends class Device
class InternetCard : public Device
{
  public:
    // constructor, just receive the name of this card
    InternetCard(std::string name) : name_(std::move(name)) {}

    // method sendIn, it will just print the helpful info simply
    void sendIn()
    {
        // https://en.cppreference.com/w/cpp/thread/shared_lock
        // locks the associated shared mutex in shared mode
        std::shared_lock lock(mutexForExec_);
        std::cout << name_ << " is sending..." << std::endl;
    }
    // method recvFrom, it will just print the helpful info simply
    void recvFrom()
    {
        // https://en.cppreference.com/w/cpp/thread/unique_lock
        // locks the associated shared mutex in exclusive mode
        std::unique_lock lock(mutexForExec_);
        std::cout << name_ << " is receiving..." << std::endl;
    }

private:
    // the shared mutex to make sure that method sendIn will block
    // when method recvFrom is calling
    std::shared_mutex mutexForExec_;
    // the name of this card
    std::string name_;
};
