/*
Q-URL: https://leetcode-cn.com/problems/integer-to-english-words/
# BEATS 100%
*/

class Solution {
public:
    string numberToWords(int num) {
        if (num < 1000) {
            return helper(num);
        }

        constexpr const char *splits[] {
            " Thousand ", " Million ", " Billion ",
            " Thousand", " Million", " Billion"
        };

        auto result = helper(num % 1000);
        for (int i = 0; i < 3; ++i) {
            num /= 1000;
            if (num) {
                if (num % 1000) {
                    if (result == "Zero") {
                        result = helper(num % 1000) + splits[i + 3];
                    } else {
                        result = helper(num % 1000) + splits[i] + result;
                    }
                }
            } else {
                break;
            }
        }

        return result;
    }

private:
    string helper(int num) {
        constexpr const char *digits[] {
            "Zero", "One", "Two", "Three", "Four",
            "Five", "Six", "Seven", "Eight", "Nine",
            "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
            "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
        };
        constexpr const char *tens[] {
            "Twenty", "Thirty", "Forty", "Fifty",
            "Sixty", "Seventy", "Eighty", "Ninety"
        };

        if (num < 20) {
            return digits[num];
        } else if (num % 100 == 0) {
            return digits[num / 100] + " Hundred"s;
        }

        auto _1 = num / 100;
        auto _2 = (num / 10) % 10;
        auto _3 = num % 10;

        string result;
        if (_2 < 2) {
            result = digits[num % 100];
        } else if (_3 == 0) {
            result = tens[_2 - 2];
        } else {
            result = digits[_3];
            if (_2) {
                result = tens[_2 - 2] + " "s + result;
            }
        }
        if (_1) {
            result = digits[_1] + " Hundred "s + result;
        }

        return result;
    }
};
