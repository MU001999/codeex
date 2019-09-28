#pragma once

#include <string>

namespace design_patterns
{
// abstract base class Product
class Product
{
  public:
    // pure virtual destructor but with definition
    virtual ~Product() = 0;
    // pure virtual method getInfo
    // return the info of product
    virtual std::string getInfo() const = 0;
};

// definition for Product's destructor
inline Product::~Product() {}

// derived class HaierTV extends Product
class HaierTV final : public Product
{
  public:
    // return the info of HaierTV
    std::string getInfo() const override
    {
        return "A HaierTV is producted LOL";
    }
};

// derived class TCLFridge extends Product
class TCLFridge final : public Product
{
  public:
    // return the info of TCLFridge
    std::string getInfo() const override
    {
        return "A TCLFridge is producted LOL";
    }
};

// derived class HisenseMobilephone extends Product
class HisenseMobilephone final : public Product
{
  public:
    // return the info of HisenseMobilephone
    std::string getInfo() const override
    {
        return "A HisenseMobilephone is producted LOL";
    }
};

// derived class AppleTV extends Product
class AppleTV final : public Product
{
  public:
    // return the info of AppleTV
    std::string getInfo() const override
    {
        return "A AppleTV is producted LOL";
    }
};

// derived class AppleFridge extends Product
class AppleFridge final : public Product
{
  public:
    // return the info of AppleFridge
    std::string getInfo() const override
    {
        return "A AppleFridge is producted LOL";
    }
};
} // namespace design_patterns
