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

    operator const char *() const
    {
        return str;
    }
};

int main()
{
    String s("Hello!");

    const char *sz = s;
    cout << sz << endl;

    return 0;
}