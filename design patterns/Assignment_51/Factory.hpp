#pragma once

#include <memory>
#include <string>
#include "Product.hpp"

namespace design_patterns
{
namespace
{
constexpr std::size_t operator""hash(const char *str, std::size_t len)
{
    if (len == 0)
    {
        return 0;
    }
    else
    {
        return (*str * *str + operator""hash(str + 1, len - 1)) % 13717;
    }
}

std::size_t hash(const std::string &str)
{
    return operator""hash(str.c_str(), str.size() + 1);
}
} // namespace

class Factory
{
  public:
    virtual ~Factory() = 0;

    virtual std::shared_ptr<Product>
    createProduct(const std::string &type) = 0;
};

inline Factory::~Factory()
{
    // ...
}

class HaierFactory final : public Factory
{
  public:
    HaierFactory() = default;

    std::shared_ptr<Product>
    createProduct(const std::string &type)
    {
        switch (hash(type))
        {
        case "TV"hash:
            return std::make_shared<HaierTV>();
        default:
            return nullptr;
        }
    }
};

class TCLFactory final : public Factory
{

};

class HisenseFactory final : public Factory
{

};

class AppleFactory final : public Factory
{

};
} // namespace design_patterns
