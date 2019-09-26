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
    // pure virtual destructor but with definition
    virtual ~Text() = 0;
    // pure virtual method
    // return the text
    virtual T getText() const = 0;
};

// definition for Text's destructor
template <typename T>
inline Text<T>::~Text() {}

// derived class PalinText extends Text
template <typename T>
class PlainText final : public Text<T>
{
  public:
    // constructor
    // param text: text will be set to
    //             he plain text owned by this class
    PlainText(T text) : text_(std::move(text))
    {
        // do nothing
    }

    // implement of getText
    // return the plain text
    T getText() const override
    {
        return text_;
    }

  private:
    // the raw text
    const T text_;
};
} // namespace design_patterns
