#include <iostream>

using namespace std;

char *resize(char *str, unsigned size, unsigned new_size)
{
    if(size == 0)
    {
        char* newStr = new char[1];
        return newStr;

    }
    char* newStr = new char[new_size];
    for(int i = 0; (i < size) && (i < new_size); i++)
    {
        newStr[i] = str[i];
    }
    delete[] str;
    return newStr;
}

char *getline()
{
    char token;
    unsigned size = 0;
    char* str;
    while(1)
    {

        if (std::cin.get(token) && token != '\n')
        {
            str = resize(str, size, size+1);
            str[size] = token;
            size++;
        }
        else
        {
            str = resize(str, size, size+1);
            str[size] = '\0';
            return str;
        }
    }
}
