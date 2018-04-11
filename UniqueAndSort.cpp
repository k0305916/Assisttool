#include <iostream>
#include <set>
#include <algorithm>

int main()
{
    auto count = 0;
    while (std::cin >> count)
    {
        std::set<long> iset;
        while (count-- >= 0)
        {
            std::string input;
            getline(std::cin, input);
            if (input.compare("") == 0)
                continue;
            iset.insert(std::strtol(input.c_str(),nullptr,0));
        }
        for (auto temp : iset)
        {
            std::cout << temp << std::endl;
        }
    }
    return 0;
}