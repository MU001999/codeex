#pragma once

#include <mutex>
#include <queue>
#include <thread>
#include <memory>
#include <functional>
#include <condition_variable>
#include "Command.hpp"

class OS
{
  public:
    OS() : stop_(false) {}

    void run()
    {
        stop_ = false;
        std::thread tForExecReadOps([this]{ this->executeReadCommands(); });
        std::thread tForExecWriteOps([this]{ this->executeWriteCommands(); });
        tForExecReadOps.detach();
        tForExecWriteOps.detach();
    }
    void stop()
    {
        stop_ = true;
    }
    void addReadCommand(std::shared_ptr<Command> command)
    {
        if (readCommands_.empty())
        {
            readCommands_.push(command);
            cvForROps_.notify_one();
        }
        else
        {
            readCommands_.push(command);
        }
    }
    void addWriteCommand(std::shared_ptr<Command> command)
    {
        if (writeCommands_.empty())
        {
            writeCommands_.push(command);
            cvForWOps_.notify_one();
        }
        else
        {
            writeCommands_.push(command);
        }
    }

  private:
    void executeReadCommands()
    {
        while (true)
        {
            if (stop_)
            {
                break;
            }
            if (readCommands_.empty())
            {
                using namespace std::literals::chrono_literals;
                std::unique_lock lock(mutexForROps_);
                cvForROps_.wait_for(lock, 20ms, [this] { return !this->readCommands_.empty(); });
            }
            else
            {
                auto command = readCommands_.front();
                readCommands_.pop();
                command->execute();
            }
        }
    }
    void executeWriteCommands()
    {
        while (true)
        {
            if (stop_)
            {
                break;
            }
            if (writeCommands_.empty())
            {
                using namespace std::literals::chrono_literals;
                std::unique_lock lock(mutexForWOps_);
                cvForWOps_.wait_for(lock, 20ms, [this] { return !this->writeCommands_.empty(); });
            }
            else
            {
                auto command = writeCommands_.front();
                writeCommands_.pop();
                command->execute();
            }
        }
    }

    std::queue<std::shared_ptr<Command>> readCommands_;
    std::mutex mutexForROps_;
    std::condition_variable cvForROps_;

    std::queue<std::shared_ptr<Command>> writeCommands_;
    std::mutex mutexForWOps_;
    std::condition_variable cvForWOps_;

    bool stop_;
};
