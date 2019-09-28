#pragma once

#include <memory>
#include <string>
#include <exception>
#include "Product.hpp"

namespace design_patterns
{
namespace
{
// hash function for compile-time string
constexpr std::size_t operator""_hash(const char *str, std::size_t len)
{
    if (len == 0)
    {
        return 0;
    }
    else
    {
        return (*str * *str + operator""_hash(str + 1, len - 1)) % 13717;
    }
}

// hash function for running-time string by calling operator""_hash
std::size_t hash(const std::string &str)
{
    return operator""_hash(str.c_str(), str.size() + 1);
}
} // namespace

// abstract base class Factory
class Factory
{
  public:
    // pure virtual destructor but with definition
    virtual ~Factory() = 0;

    // pure virtual method
    // create product by received type
    // param type: the return type user want
    // return a pointer to the created product
    // may throw an exception about any invalid type
    virtual std::shared_ptr<Product>
    createProduct(const std::string &type) = 0;
};

// definition for Factory's destructor
inline Factory::~Factory() {}

// derived class HaierFactory extends Factory
class HaierFactory final : public Factory
{
  public:
    // default constructor
    HaierFactory() = default;

    // create product by received type
    // param type: the return type user want
    // return a pointer to the created product
    // may throw an exception about any invalid type
    std::shared_ptr<Product>
    createProduct(const std::string &type) override
    {
        // return the product needed belong to the type
        switch (hash(type))
        {
        case "TV"_hash:
            return std::make_shared<HaierTV>();
        default:
            // no match then throw an exception
            throw std::invalid_argument("invalid argument type in calling createProduct, "
                "no such type for " + type + " in HaierFactory");
        }
    }
};

class TCLFactory final : public Factory
{
  public:
    // default constructor
    TCLFactory() = default;

    // create product by received type
    // param type: the return type user want
    // return a pointer to the created product
    // may throw an exception about any invalid type
    std::shared_ptr<Product>
    createProduct(const std::string &type) override
    {
        // return the product needed belong to the type
        switch (hash(type))
        {
        case "Fridge"_hash:
            return std::make_shared<TCLFridge>();
        default:
            // no match then throw an exception
            throw std::invalid_argument("invalid argument type in calling createProduct, "
                "no such type for " + type + " in TCLFactory");
        }
    }
};

class HisenseFactory final : public Factory
{
  public:
    // default constructor
    HisenseFactory() = default;

    // create product by received type
    // param type: the return type user want
    // return a pointer to the created product
    // may throw an exception about any invalid type
    std::shared_ptr<Product>
    createProduct(const std::string &type) override
    {
        // return the product needed belong to the type
        switch (hash(type))
        {
        case "Mobilephone"_hash:
            return std::make_shared<HisenseMobilephone>();
        default:
            // no match then throw an exception
            throw std::invalid_argument("invalid argument type in calling createProduct, "
                "no such type for " + type + " in HisenseFactory");
        }
    }
};

class AppleFactory final : public Factory
{
  public:
    // default constructor
    AppleFactory() = default;

    // create product by received type
    // param type: the return type user want
    // return a pointer to the created product
    // may throw an exception about any invalid type
    std::shared_ptr<Product>
    createProduct(const std::string &type) override
    {
        // return the product needed belong to the type
        switch (hash(type))
        {
        case "TV"_hash:
            return std::make_shared<AppleTV>();
        case "Fridge"_hash:
            return std::make_shared<AppleFridge>();
        default:
            // no match then throw an exception
            throw std::invalid_argument("invalid argument type in calling createProduct, "
                "no such type for " + type + " in AppleFactory");
        }
    }
};
} // namespace design_patterns
