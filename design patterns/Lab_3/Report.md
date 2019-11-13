# Report for Lab 3

> This is the report for case 1

## 1. Analysis of Lab Task

Describe the task, what patterns I choose and why I choose these patterns.

## 2. Overall Design

Give the UMLs but with no detail codes, and then describe these classes.

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

Full of detail codes and describe all the processes.

## 4. Test Procedure

Describe the procedure of testing with the example result.

## 5. Conclusion

Conclude the conclusion.
