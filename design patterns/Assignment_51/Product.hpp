#pragma once

#include <string>

namespace design_patterns
{
class Product
{
  public:
    virtual ~Product() = 0;
    virtual std::string getInfo() = 0;
};

inline Product::~Product()
{
    // ...
}

class HaierTV final : public Product
{

};

class TCLFridge final : public Product
{

};

class HisenseMobilephone final : public Product
{

};
} // namespace design_patterns
