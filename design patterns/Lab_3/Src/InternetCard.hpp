#pragma once

#include <thread>
#include <string>
#include <iostream>
#include <shared_mutex>
#include "Device.hpp"

class InternetCard : public Device
{
  public:
    InternetCard(std::string name) : name_(std::move(name)) {}

    void sendIn()
    {
        std::shared_lock lock(mutexForExec_);
        std::cout << name_ << " is sending..." << std::endl;
    }
    void recvFrom()
    {
        std::unique_lock lock(mutexForExec_);
        std::cout << name_ << " is receiving..." << std::endl;
    }

private:
    std::shared_mutex mutexForExec_;
    std::string name_;
};
