#include <iostream>
using namespace std;

class SimpleClass
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
    void ShowNum() const
    {
        // const 함수는 const 함수만 호출할 수 있다.
        cout << GetNum() << endl;
    }
};

int main()
{
    SimpleClass sc;
    sc.InitNum(3);
    sc.ShowNum();

    return 0;
}