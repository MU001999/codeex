#pragma once

class Device
{
  public:
    virtual ~Device() = 0;
};

inline Device::~Device() = default;
