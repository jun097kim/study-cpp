#include <iostream>
using namespace std;

class EasyClass
{
private:
    int num;

public:
    void InitNum(int n)
    {
        num = n;
    }
    int GetNum() const
    {
        return num;
    }
};

class LiveClass
{
private:
    int num;

public:
    void InitNum(const EasyClass &easy)
    {
        num = easy.GetNum();
    }
};

int main()
{
    EasyClass ec;
    ec.InitNum(3);

    LiveClass lc;
    lc.InitNum(ec);

    return 0;
}