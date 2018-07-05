#include <cctype>
#include <string>
#include <sstream>
#include <unordered_map>

static int& getReg(std::unordered_map<std::string, int>& regs, std::string name)
{
    return regs[name];
}

std::unordered_map<std::string, int> assembler(const std::vector<std::string>& program)
{
    std::unordered_map<std::string, int> regs;
    
    std::string head;
    std::string arg1;
    std::string arg2;
    
    size_t i = 0;
    while (i < program.size())
    {
        auto ins = program[i];
        std::stringstream ss;
        ss << ins;
        ss >> head;
        if (head == "mov")
        {
            ss >> arg1;
            ss >> arg2;
            regs[arg1] = (regs.find(arg2) != regs.end()) ? getReg(regs, arg2) : std::atoi(arg2.c_str());
        }
        else if (head == "inc")
        {
            ss >> arg1;
            ++getReg(regs, arg1);
        }
        else if (head == "dec")
        {
            ss >> arg1;
            --getReg(regs, arg1);
        }
        else
        {
            ss >> arg1;
            ss >> arg2;
            if (((regs.find(arg1) != regs.end()) ? getReg(regs, arg1) : std::atoi(arg1.c_str())) != 0)
            {
                i += (regs.find(arg2) != regs.end()) ? getReg(regs, arg2) : std::atoi(arg2.c_str());
                continue;
            }
        }
        ++i;
    }
    
    return regs;
}
