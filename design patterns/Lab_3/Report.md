# Report for Lab 3

> This is the report for case 1

## 1. Analysis of Lab Task

In lab 3, the task is that there some I/O devices, which support read and write operations, and one OS to employ queues to manage all the read-write requets.

So I design this program with command pattern, read or write operation for each device will be set to an object. And tasks for OS are just to call the uniform interface provided by the objects' common base class Command. Also OS will detach two threads to execute commands.

## 2. Overall Design

There are some overall descriptions for classes I designed.

### 2.1 Devices

There is an abstract base class Device for all devices and three concrete classes named InternetCard, Ram and SoundCard, which extend Device. Each device will have its own methods for reading or executing.

### 2.2 Commands

I design three abstract classes for commands. The first is class Command, which is the base class for all command objects.

All commands can be segregated to read commands and write commands. So I design two another abstract classes named ReadCommand and WriteCommand extend class Command.

After all, there are three concrete classes named InternetCardReadCommand, RamReadCommand and SoundCardReadCommand extend ReadCommand and three concrete classes named InternetCardWriteCommand, RamWriteCommand and SoundCardWriteCommand extend WriteCommand.

Each concrete command object has a pointer to the corresponding device object, so we can call the uniform interface but not care about the concrete methods of devices.

### 2.3 OS

OS is a concrete class to manage added commands (operations). This class contains two queues, one for read commands and another one for write commands. OS provides four methods, two for run and stop and another two for add commands.

In method run, OS will init two threads to execute read-write commands individually. And there will be some ways to avoid problems in multi-threads. Method stop will set a flag to make this system stop.

Methods addReadCommand and addWriteCommand are to add commands to corresponding queues.

And OS has other private methods named executeReadCommands and executeWriteCommands whitch will be called in the two threads inited in the method run.

<div STYLE="page-break-after: always;"></div>

### 2.4 UML Class Diagram

The linkage of these objects is shown by the following diagram:

@startuml
Device <|-- InternetCard
Device <|-- Ram
Device <|-- SoundCard

Command <|-- ReadCommand
Command <|-- WriteCommand

ReadCommand <|-- InternetCardReadCommond
ReadCommand <|-- RamReadCommond
ReadCommand <|-- SoundCardReadCommond

WriteCommand <|-- InternetCardWriteCommond
WriteCommand <|-- RamWriteCommond
WriteCommand <|-- SoundCardWriteCommond

InternetCard <.. InternetCardReadCommond
InternetCard <.. InternetCardWriteCommond

Ram <.. RamReadCommond
Ram <.. RamWriteCommond

SoundCard <.. SoundCardReadCommond
SoundCard <.. SoundCardWriteCommond

ReadCommand o-- OS
WriteCommand o-- OS

abstract class Device

class InternetCard
{
__ attributes __
-name: string
-mutexForExec: shared_mutex
__ operations __
+sendIn
+recvFrom
}

class Ram
{
__ attributes __
-name: string
-mutexForExec: shared_mutex
__ operations __
+read
+write
}

class SoundCard
{
__ attributes __
-name: string
-mutexForExec: shared_mutex
__ operations __
+play
+record
}

abstract class Command
{
__ operations __
+execute{abstract}
+sleepRandom{static}
}

abstract class ReadCommand
{
__ operations __
+execute{abstract}
}

abstract class WriteCommand
{
__ operations __
+execute{abstract}
}

class InternetCardReadCommond
{
__ attributes __
-internetCard: shared_ptr<InternetCard>
__ operations __
+execute
}

class InternetCardWriteCommond
{
__ attributes __
-internetCard: shared_ptr<InternetCard>
__ operations __
+execute
}

class RamReadCommond
{
__ attributes __
-internetCard: shared_ptr<Ram>
__ operations __
+execute
}

class RamWriteCommond
{
__ attributes __
-internetCard: shared_ptr<Ram>
__ operations __
+execute
}

class SoundCardReadCommond
{
__ attributes __
-internetCard: shared_ptr<SoundCard>
__ operations __
+execute
}

class SoundCardWriteCommond
{
__ attributes __
-internetCard: shared_ptr<SoundCard>
__ operations __
+execute
}

class OS
{
__ attributes __
-stop: bool
-readCommands: queue<shared_ptr<ReadCommand>>
-writeCommands: queue<shared_ptr<WriteCommand>>
-mutexForROps: mutex
-mutexForWOps: mutex
-cvForROps: condition_variable
-cvForWOps: condition_variable
__ operations __
+run
+stop
+addReadCommand(...)
+addWriteCommand(...)
-executeReadCommands
-executeWriteCommands
}
@enduml

## 3. Key Components and Detailed Design

In this section, I will introduce these classes with their implementations in detial.

### 3.1 Devices' Assignments

Each concrete device class has two methods for read operation and write operation. For instance, the two methods named sendIn and recvFrom in class InternetCard. And then I will introduce the implementations with an example in InternetCard's because the other two are like it.

```cpp
class InternetCard : public Device
{
  public:
    InternetCard(std::string name) : name_(std::move(name)) {}

    void sendIn()
    {
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
```

Let's look at the InternetCard's implementation above. The constructor is easy to understand. In these two methods, I make locks to make sure the two will block themselves when the other is executing. But some read operations can execute together at the same time.

I [locks the shared mutex in shared mode](https://en.cppreference.com/w/cpp/thread/shared_lock) at first in method sendIn and [locks the shared mutex in exclusive mode](https://en.cppreference.com/w/cpp/thread/unique_lock) at the beginning of method recvFrom in order to make sure things will be done as mentioned in the previous paragraph.

### 3.2 Commands' Simple Actions

Commands extend the same base class Command with only one interface named execute, the following code is the defination of classes Command, ReadCommand and WriteCommand:

```cpp
class Command
{
  public:
    virtual ~Command() = default;
    virtual void execute() = 0;
    static void sleepRandom();
};

class ReadCommand  : public Command
{
  public:
    virtual ~ReadCommand() = default;
    virtual void execute() = 0;
};

class WriteCommand : public Command
{
  public:
    virtual ~WriteCommand() = default;
    virtual void execute() = 0;
};
```

In my implementatin, I write a helpful macro to help generate all similar concrete command classes, so look at the following code of the macro:

```cpp
#define GEN_COMMAND(Device, Op, Name, Method) \
class Device##Op##Command final : public Op##Command \
{ \
  public: \
    Device##Op##Command(std::shared_ptr<Device> Name) \
      : Name##_(Name) \
    {} \
    void execute() override \
    { \
        Command::sleepRandom(); \
        Name##_->Method(); \
    } \
  private: \
    std::shared_ptr<Device> Name##_; \
}
```

*Device* is the param on behalf of which device this macro generate class for, *Op* on behalf of which op to call when calling the method execute, *Name* for the user-defined member variable's name in this generated class and *Command* means the real method's name of the given device class.

For example, a generated class by using `GEN_COMMAND(InternetCard, Read, internetCard, sendIn);` will like the following InternetCardReadCommand:

```cpp
class InternetCardReadCommand final : public ReadCommand
{
  public:
    InternetCardReadCommand(std::shared_ptr<InternetCard> internetCard)
     : internetCard_(internetCard) {}

    void execute() override
    {
        Command::sleepRandom();
        internetCard_->sendIn();
    }

  private:
    std::shared_ptr<InternetCard> internetCard_;
};
```

Maybe you will feel puzzled when you see `Command::sleepRamdom();`, I will explain it in section 4.

### 3.3 OS's Execution Process

The most complex part I think in this lab is the OS's implementation, I will give the declaration of it as the following firstly and then introduce it in detail through segregated parts.

```cpp
class OS
{
  public:
    OS() : stop_(false) {}

    void run();
    void stop();
    void addReadCommand(std::shared_ptr<ReadCommand> command);
    void addWriteCommand(std::shared_ptr<WriteCommand> command);

  private:
    void executeReadCommands();
    void executeWriteCommands();

    std::queue<std::shared_ptr<ReadCommand>> readCommands_;
    std::mutex mutexForROps_;
    std::condition_variable cvForROps_;

    std::queue<std::shared_ptr<WriteCommand>> writeCommands_;
    std::mutex mutexForWOps_;
    std::condition_variable cvForWOps_;

    bool stop_;
};
```

As we can see, there are four public methods and two private methods, I will introduce them one by one and these member variables will be included.

Actually if we want to let an instance of OS run, we should construct it and then call the method run. Of course commands could be added before or after the call as you like. This is the implementation of method run:

```cpp
void run()
{
    stop_ = false;
    std::thread tForExecReadOps([this]{ this->executeReadCommands(); });
    std::thread tForExecWriteOps([this]{ this->executeWriteCommands(); });
    tForExecReadOps.detach();
    tForExecWriteOps.detach();
}
```

In fact method run may be called after being stoped, so it will set stop_ to false to make sure the threads will run as expected. Then there will be two [threads](https://en.cppreference.com/w/cpp/thread/thread), one for read commands and another one for write commands, received real functions for exeucting commands. The two threads will be detached from the main thread after constructions.

Maybe the OS will be shutdown with the time, we need to stop it at the time. So it's time to show method stop:

```cpp
void stop()
{
    stop_ = true;
}
```

It's very simple and easy to understand, the method will just set stop_ to true. Then progress in threads, started in method run, will stop and return because the change of stop_ from true to false.

Then I will introduce the two private methods firstly, these methods are designed for threads to run. And I will only show the implementation of method executeReadCommands, another one is like it with difference at the involved member variables.

```cpp
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
            // https://en.cppreference.com/w/cpp/thread/condition_variable/wait_for
            cvForROps_.wait_for(lock, 20ms, [this] { return !this->readCommands_.empty(); });
        }
        // else if queue if not empty
        else
        {
            auto command = readCommands_.front();
            readCommands_.pop();
            command->execute();
        }
    }
}
```

What in method executeReadCommand is a while-true loop, contains the management for commands. In each loop, variable stop_ will be checked to determine whether to quit or not. It will continue to run if stop_ is false.

Let's go on. If readCommands is empty, it will locks, which is just for the later [wait-for statement](https://en.cppreference.com/w/cpp/thread/condition_variable/wait_for), and block until the queue is not empty or for 20ms.

Else if the queue if not empty, it will just get and pop the front element of the queue and then execute the command got.

Finally only method addReadCommand and addWriteCommand left, I will introduce the implementation of addReadCommand ad the following:

```cpp
void addReadCommand(std::shared_ptr<ReadCommand> command)
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
```

This method is simple, it will check whether the queue is empty or not. It will push the given command to readCommands_ and then [notify](https://en.cppreference.com/w/cpp/thread/condition_variable/notify_one) the blocked thread to continue to run if the queue is empty. Or it will just push the given command to readCommands_ if the queue is not empty.

## 4. Test Procedure

### 4.1 Test Code

I designed a simple test for this lab as the following code:

```cpp
int main(int argc, char *argv[])
{
    OS os; os.run();

    auto internetCard = make_shared<InternetCard>("icard");
    auto ram = make_shared<Ram>("ram");
    auto soundCard = make_shared<SoundCard>("scard");

    vector<shared_ptr<ReadCommand>> readCommands
    {
        make_shared<InternetCardReadCommand>(internetCard),
        make_shared<RamReadCommand>(ram),
        make_shared<SoundCardReadCommand>(soundCard)
    };

    vector<shared_ptr<WriteCommand>> writeCommands
    {
        make_shared<InternetCardWriteCommand>(internetCard),
        make_shared<RamWriteCommand>(ram),
        make_shared<SoundCardWriteCommand>(soundCard)
    };

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> disInt(0, 2);
    for (int i = 0; i < 5; ++i)
    {
        Command::sleepRandom();
        os.addReadCommand(readCommands[disInt(gen)]);
        Command::sleepRandom();
        os.addWriteCommand(writeCommands[disInt(gen)]);
    }

    this_thread::sleep_for(1s);
    os.stop();

    return 0;
}
```

At first, I declare the divices and corresponding commands for the divices. And these commands will be added randomly to the os, then the main thread will sleep for 1s. The os will stop finally.

You may feel confused about statement `Command::sleepRandom();`, it will action as its name to sleep for a random time between 0ms ~ 1ms simply.

### 4.2 Example Result

I run this test and get an example result of it as the following:

```plaintext
ram is reading...
ram is writing...
ram is reading...
icard is receiving...
icard is sending...
ram is writing...
icard is sending...
icard is receiving...
scard is playing...
icard is receiving...
```

## 5. Conclusion

It's an interesting assignment for me. In this lab, I learned the command pattern and try to use it. And I also acquired a better understanding of multi-threads.
