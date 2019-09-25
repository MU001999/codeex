#pragma once

#include <utility>

namespace design_patterns
{
template <typename T>
class Text
{
  public:
    virtual ~Text() = 0;
    virtual T getText() = 0;
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

    T getText() override
    {
        return text_;
    }

  private:
    const T text_;
};

template <typename T>
class EncryptedText final : public Text<T>
{
  public:
    EncryptedText(T text) : text_(std::move(text))
    {
        // do nothing
    }

    T getText() override
    {
        return text_;
    }

  private:
    const T text_;
};
} // namespace design_patterns
