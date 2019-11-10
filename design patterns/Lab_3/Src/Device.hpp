#pragma once

// simple abstract class Device
class Device
{
  public:
    // make sure that there is no instance of this class
    virtual ~Device() = 0;
};

// pure virtual destructor but should with defination
inline Device::~Device() = default;
