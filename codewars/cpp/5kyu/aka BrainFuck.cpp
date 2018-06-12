/*
Q-URL: https://www.codewars.com/kata/my-smallest-code-interpreter-aka-brainf-star-star-k/cpp
*/

#include <string>
#include <vector>

// using vector
std::string brainLuck(std::string code, std::string input)
{
    const char *reading = code.c_str();
    const char *inputp = input.c_str();
    
    std::vector<char> data{0};
    size_t data_ptr = 0;
    
    std::string res;
    
    while (*reading)
    {
        switch (*reading)
        {
            case '>':
                if (data.size() == 1 + data_ptr++) data.push_back(0);
                break;
            case '<':
                --data_ptr;
                break;
            case '+':
                if (data[data_ptr] == 255) data[data_ptr] = 0;
                else ++data[data_ptr];
                break;
            case '-':
                if (data[data_ptr] == 0) data[data_ptr] = 255;
                else --data[data_ptr];
                break;
            case '.':
                res += data[data_ptr];
                break;
            case ',':
                data[data_ptr] = *(inputp++);
                break;
            case '[':
                if (data[data_ptr] == 0) 
                {
                    int lefts = 0;
                    while (*reading)
                    {
                        if (*reading == '[') ++lefts;
                        else if (*reading == ']' && lefts == 1) break;
                        else if (*reading == ']') --lefts;
                        ++reading;
                    }
                }
                break;
            case ']':
                if (data[data_ptr] != 0)
                {
                    int rights = 0;
                    while (*reading)
                    {
                        if (*reading == ']') ++rights;
                        else if (*reading == '[' && rights == 1) break;
                        else if (*reading == '[') --rights;
                        --reading;
                    }
                }
                break;
            default: break;
        }
        ++reading;
    }
    return res;
}

// without vector
#include <string>

struct node
{
    node *left;
    char value;
    node *right;
    
    node(node *left, char value, node *right) : left(left), value(value), right(right) {}
};


std::string brainLuck(std::string code, std::string input)
{
    const char *reading = code.c_str();
    const char *inputp = input.c_str();
    
    node *data_pointer = new node(nullptr, 0, nullptr);
    
    std::string res;
    
    while (*reading)
    {
        switch (*reading)
        {
            case '>':
                if (data_pointer->right == nullptr)
                  data_pointer->right = new node(data_pointer, 0, nullptr); 
                data_pointer = data_pointer->right;
                break;
            case '<':
                if (data_pointer->left == nullptr)
                  data_pointer->left = new node(nullptr, 0, data_pointer); 
                data_pointer = data_pointer->left;
                break;
            case '+':
                if (data_pointer->value == 255) data_pointer->value = 0;
                else ++(data_pointer->value);
                break;
            case '-':
                if (data_pointer->value == 0) data_pointer->value = 255;
                else --(data_pointer->value);
                break;
            case '.':
                res += data_pointer->value;
                break;
            case ',':
                data_pointer->value = *(inputp++);
                break;
            case '[':
                if (data_pointer->value == 0) 
                {
                    int lefts = 0;
                    while (*reading)
                    {
                        if (*reading == '[') ++lefts;
                        else if (*reading == ']' && lefts == 1) break;
                        else if (*reading == ']') --lefts;
                        ++reading;
                    }
                }
                break;
            case ']':
                if (data_pointer->value != 0)
                {
                    int rights = 0;
                    while (*reading)
                    {
                        if (*reading == ']') ++rights;
                        else if (*reading == '[' && rights == 1) break;
                        else if (*reading == '[') --rights;
                        --reading;
                    }
                }
                break;
            default: break;
        }
        ++reading;
    }
    return res;
}