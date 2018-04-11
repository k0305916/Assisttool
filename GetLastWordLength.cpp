#include <iostream>
#include <sstream>
#include <string>

int GetLastWordLen(std::string str)
{
    if(str.empty())
        return 0;
    std::istringstream istr(str);
    std::string lastword;
    while(istr>>lastword){};
    return lastword.length();
}

int main(int agr, char** agv)
{
    std::string input;
    getline(std::cin,input);
    std::cout << GetLastWordLen(input) << std::endl;
    return 0;
}