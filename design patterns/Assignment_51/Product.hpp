#pragma once

#include <string>

namespace design_patterns
{
class Product
{
  public:
    virtual ~Product() = 0;
    virtual std::string getInfo() const = 0;
};

inline Product::~Product()
{
    // ...
}

class HaierTV final : public Product
{
  public:
    std::string getInfo() const override
    {
        return "A HaierTV is producted LOL"s;
    }
};

class TCLFridge final : public Product
{
  public:
    std::string getInfo() const override
    {
        return "A TCLFridge is producted LOL"s;
    }
};

class HisenseMobilephone final : public Product
{
  public:
    std::string getInfo() const override
    {
        return "A HisenseMobilephone is producted LOL"s;
    }
};

class AppleTV final : public Product
{
  public:
    std::string getInfo() const override
    {
        return "A AppleTV is producted LOL"s;
    }
};

class AppleFridge final : public Product
{
  public:
    std::string getInfo() const override
    {
        return "A AppleFridge is producted LOL"s;
    }
};
} // namespace design_patterns
