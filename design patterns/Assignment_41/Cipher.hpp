#pragma once

#include <utility>
#include <iterator>
#include <algorithm>
#include "Text.hpp"

namespace design_patterns
{
// absrtact derived class CipherDecorator extends Text
// but as the base class for decorators
template <typename T>
class CipherDecorator : public Text<T>
{
  public:
    // constructor
    // param text: text will be set to the private
    //             member for decorating
    CipherDecorator(const Text<T> &text)
      : text_(text)
    {
        // do nothing
    }
    // pure virtual destructor but with definition
    virtual ~CipherDecorator() = 0;

  protected:
    // the component to decorate
    const Text<T> &text_;
};

// definition for CipherDecorator's destructor
template <typename T>
inline CipherDecorator<T>::~CipherDecorator() {}

// derived class SimpleEncrypt extends CipherDecorator
// it's just used to move each letter in the Text
template <typename T>
class SimpleEncrypt final : public CipherDecorator<T>
{
  public:
    // constructor
    // param text: text will be set to the private
    //             member for decorating
    // param step: step of moving each letter,
    //             default with 5
    SimpleEncrypt(const Text<T> &text, int step = 5)
      : CipherDecorator<T>(text), step_(step)
    {
        // do nothing
    }

    // implement of getText
    // return the encrypted text
    T getText() const override
    {
        // get the literal from the text_
        auto literal = this->text_.getText();
        // decl another var for returning
        T result = literal;
        // move for each letter
        for (std::size_t i = 0; i < literal.size(); ++i)
        {
            result[(i + step_) % result.size()] = literal[i];
        }
        // just return the result
        return result;
    }

  private:
    // store the step for moving
    const int step_;
};

// derived class ReverseEncrypt extends CipherDecorator
// it's just used to reverse the text got from previous level
template <typename T>
class ReverseEncrypt final : public CipherDecorator<T>
{
  public:
    // constructor
    // param text: text will be set to the private
    //             member for decorating
    ReverseEncrypt(const Text<T> &text)
      : CipherDecorator<T>(text)
    {
        // do nothing
    }

    // implement of getText
    // return the reversed text
    T getText() const override
    {
        // get the literal from the text_
        auto literal = this->text_.getText();
        // reverse the literal
        std::reverse(std::begin(literal), std::end(literal));
        // just return the result
        return literal;
    }
};

// derived class SimpleEncrypt extends CipherDecorator
// it's just used to encrypt the text got from previous level
// by a simple method
template <typename T>
class ComplexEncrypt final : public CipherDecorator<T>
{
  public:
    // constructor
    // param text: text will be set to the private
    //             member for decorating
    // param leap: leap length of each letter,
    //             default with 5
    ComplexEncrypt(const Text<T> &text, int leap = 5)
      : CipherDecorator<T>(text), leap_(leap)
    {
        // do nothing
    }

    // implement of getText
    // return the encrypted text
    T getText() const override
    {
        // get the literal from the text_
        auto literal = this->text_.getText();
        // for each letter
        for (auto &each : literal)
        {
            // just leap, it's simple
            // and I not plan to fix the overflow error LOL
            each = each + leap_;
        }
        // just return the result
        return literal;
    }

  private:
    // store the leap length
    const int leap_;
};
} // namespace design_patterns
