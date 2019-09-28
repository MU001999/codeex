#pragma once

#include <memory>
#include <string>
#include <exception>
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
    createProduct(const std::string &type) override
    {
        switch (hash(type))
        {
        case "TV"hash:
            return std::make_shared<HaierTV>();
        default:
            throw std::invalid_argument("invalid argument type in calling createProduct, no such type");
        }
    }
};

class TCLFactory final : public Factory
{
  public:
    TCLFactory() = default;

    std::shared_ptr<Product>
    createProduct(const std::string &type) override
    {
        switch (hash(type))
        {
        case "Fridge"hash:
            return std::make_shared<TCLFridge>();
        default:
            throw std::invalid_argument("invalid argument type in calling createProduct, no such type");
        }
    }
};

class HisenseFactory final : public Factory
{
  public:
    HisenseFactory() = default;

    std::shared_ptr<Product>
    createProduct(const std::string &type) override
    {
        switch (hash(type))
        {
        case "Mobilephone"hash:
            return std::make_shared<HisenseMobilephone>();
        default:
            throw std::invalid_argument("invalid argument type in calling createProduct, no such type");
        }
    }
};

class AppleFactory final : public Factory
{
  public:
    AppleFactory() = default;

    std::shared_ptr<Product>
    createProduct(const std::string &type) override
    {
        switch (hash(type))
        {
        case "TV"hash:
            return std::make_shared<AppleTV>();
        case "Fridge"hash:
            return std::make_shared<AppleFridge>();
        default:
            throw std::invalid_argument("invalid argument type in calling createProduct, no such type");
        }
    }
};
} // namespace design_patterns
