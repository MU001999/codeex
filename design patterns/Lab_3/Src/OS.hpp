#pragma once

#include <mutex>
#include <queue>
#include <thread>
#include <memory>
#include <functional>
#include <condition_variable>
#include "Command.hpp"

// concrate class OS
// can run, stop,
// add read command or add write command
class OS
{
  public:
    // simple constructor, just assign stop_ to false
    OS() : stop_(false) {}

    // method run, run two threads
    // to execute commands for reading and writing
    void run()
    {
        // reset stop_ to false, if method stop is called before
        stop_ = false;
        // init two threads, one for executing read commands
        // and another for executing write commands
        std::thread tForExecReadOps([this]{ this->executeReadCommands(); });
        std::thread tForExecWriteOps([this]{ this->executeWriteCommands(); });
        // detach these two threads
        tForExecReadOps.detach();
        tForExecWriteOps.detach();
    }
    // method stop, stop the two threads
    void stop()
    {
        // just set stop_ to true,
        // so that current commands will be executed
        stop_ = true;
    }
    // add a read command to execute later
    void addReadCommand(std::shared_ptr<ReadCommand> command)
    {
        // if no read command to execute now,
        // the thread for read commands will be notified
        if (readCommands_.empty())
        {
            readCommands_.push(command);
            cvForROps_.notify_one();
        }
        // else just push the command to the queue
        else
        {
            readCommands_.push(command);
        }
    }
    // add a write command to execute later
    void addWriteCommand(std::shared_ptr<WriteCommand> command)
    {
        // if no write command to execute now,
        // the thread for write commands will be notified
        if (writeCommands_.empty())
        {
            writeCommands_.push(command);
            cvForWOps_.notify_one();
        }
        // else just push the command to the queue
        else
        {
            writeCommands_.push(command);
        }
    }

  private:
    // real procedure to execute read commands
    void executeReadCommands()
    {
        while (true)
        {
            // if stop_ is set to true, it will break this loop
            if (stop_)
            {
                break;
            }
            // if queue for read commands is empty,
            // it means no commands to execute now
            if (readCommands_.empty())
            {
                using namespace std::literals::chrono_literals;
                // locks the associated mutex in exclusive mode
                std::unique_lock lock(mutexForROps_);
                // https://en.cppreference.com/w/cpp/thread/condition_variable/wait_for
                // this thread will block until the queue is not empty or for 20ms
                cvForROps_.wait_for(lock, 20ms, [this] { return !this->readCommands_.empty(); });
            }
            // else if queue if not empty
            else
            {
                // get, pop and then execute the front command of the queue
                auto command = readCommands_.front();
                readCommands_.pop();
                command->execute();
            }
        }
    }
    // real procedure to execute write commands
    void executeWriteCommands()
    {
        while (true)
        {
            // if stop_ is set to true, it will break this loop
            if (stop_)
            {
                break;
            }
            // if queue for write commands is empty,
            // it means no commands to execute now
            if (writeCommands_.empty())
            {
                using namespace std::literals::chrono_literals;
                // locks the associated mutex in exclusive mode
                std::unique_lock lock(mutexForWOps_);
                // https://en.cppreference.com/w/cpp/thread/condition_variable/wait_for
                // this thread will block until the queue is not empty or for 20ms
                cvForWOps_.wait_for(lock, 20ms, [this] { return !this->writeCommands_.empty(); });
            }
            // else if queue if not empty
            else
            {
                auto command = writeCommands_.front();
                writeCommands_.pop();
                command->execute();
            }
        }
    }

    // queue for read commands to execute one by one
    std::queue<std::shared_ptr<ReadCommand>> readCommands_;
    // mutex for read commands
    std::mutex mutexForROps_;
    // condition variable for read comands
    std::condition_variable cvForROps_;

    // queue for write commands to execute one by one
    std::queue<std::shared_ptr<WriteCommand>> writeCommands_;
    // mutex for write commands
    std::mutex mutexForWOps_;
    // condition variable for write comands
    std::condition_variable cvForWOps_;

    bool stop_;
};
