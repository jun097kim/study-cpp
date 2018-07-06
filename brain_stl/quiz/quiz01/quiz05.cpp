#include <iostream>
#include <cstring>
using namespace std;

class String
{
    char *str;

public:
    String(const char *str)
    {
        this->str = new char[strlen(str) + 1];
        strcpy(this->str, str);
    }

    const String& operator=(const String& arg)
    {
        delete[] str;
        str = new char[strlen(arg.str) + 1];
        strcpy(str, arg.str);
        return *this;
    }

    ~String()
    {
        delete[] str;
    }
};

int main()
{
    const char *sz = "Hello!";
    String s("Hi~!");

    s = sz; // s = String(sz);로 암묵적인 생성자를 이용한 타입 변환
    cout << sz << endl;
    
    return 0;
}