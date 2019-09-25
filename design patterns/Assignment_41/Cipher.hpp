#pragma once

#include <string>
#include <utility>
#include <iterator>
#include <algorithm>
#include "Text.hpp"

namespace design_patterns
{
template <typename T>
class CipherDecorator : public Text<T>
{
  public:
    virtual ~CipherDecorator() = 0;
};

template <typename T>
inline CipherDecorator<T>::~CipherDecorator() {}

template <typename T, int step = 5>
class SimpleEncrypt final : public CipherDecorator<T>
{
  public:
    SimpleEncrypt(Text<T> &text)
      : text_(text)
    {
        // do nothing
    }

    T getText() override
    {
        auto literal = text_.getText();
        T result = literal;
        for (std::size_t i = 0; i < literal.size(); ++i)
        {
            result[(i + step) % result.size()] = literal[i];
        }
        return result;
    }

  private:
    Text<T> &text_;
};
} // namespace design_patterns
