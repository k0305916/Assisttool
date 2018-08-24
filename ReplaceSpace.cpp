#include <iostream>
#include <string.h>

void replaceSpace(char *str, int length)
{
    for(auto i = 0;i<length;)
    {
        if(str[i] == ' ')
        {
            auto size = strlen("%20");
            char* temp = new char[length-1+size];
            memcpy(temp,str,i);
            memcpy(temp+i,"%20",size);
            memcpy(temp+i+size,str+i+1,length-size);
            length+=size-1;
            i+=size-1;
            size = strlen(temp)+1;
            if(str != nullptr)
            {
                delete str;
                str = new char[length];
                memcpy(str,temp,size);
            }
            delete temp;
            temp = nullptr;
        }
        else
            i++;
    }
}

int main()
{
    auto size = sizeof("We Are Happy.");
    char* str = new char[size];
    memcpy(str,"We Are Happy.",size);    
    replaceSpace(str,size);
    std::cout<<str<<std::endl;
    delete str;
    str = nullptr;
    return 0;
}