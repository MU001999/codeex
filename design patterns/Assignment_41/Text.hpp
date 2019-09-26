#pragma once

#include <utility>

namespace design_patterns
{
// abstract base class Text as the abstract component class
// T is the type of the data contained
template <typename T>
class Text
{
  public:
    virtual ~Text() = 0;
    virtual T getText() const = 0;
};

template <typename T>
inline Text<T>::~Text() {}

template <typename T>
class PlainText final : public Text<T>
{
  public:
    PlainText(T text) : text_(std::move(text))
    {
        // do nothing
    }

    T getText() const override
    {
        return text_;
    }

  private:
    const T text_;
};
} // namespace design_patterns
