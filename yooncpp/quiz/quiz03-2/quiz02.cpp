#include <iostream>
#include <cstring>
using namespace std;

#define STR_LEN 100

class Printer
{
private:
    char str[STR_LEN];

public:
    void SetString(char *s);
    void ShowString();
};

void Printer::SetString(char *s)
{
    strcpy(str, s);
}

void Printer::ShowString()
{
    cout << str << endl;
}

int main()
{
    Printer pnt;
    pnt.SetString("Hello world!");
    pnt.ShowString();

    pnt.SetString("I love C++");
    pnt.ShowString();
    return 0;
}