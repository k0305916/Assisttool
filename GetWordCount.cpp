#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

int GetWordCount(std::string str,char c)
{
    if(str.empty())
        return 0;
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    std::istringstream istr(str);
    std::string word;
    auto count = 0;
    while(istr >> word)
    {
        count+=std::count(word.begin(), word.end(), c);
    }
    return count;
}

int main()
{
    std::string input,compare;
    getline(std::cin, input);
    getline(std::cin,compare);
    auto result = GetWordCount(input,compare[0]);
    std::cout << result << std::endl;
    return 0;
}