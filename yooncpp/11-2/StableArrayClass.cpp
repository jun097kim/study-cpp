#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
    int *arr;
    int arrlen;
    BoundCheckIntArray(const BoundCheckIntArray& arr) { }
    BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) { }
    
public:
    BoundCheckIntArray(int len) : arrlen(len)
    {
        arr = new int[len];
    }
    int& operator[](int idx)
    {
        if (idx < 0 || idx >= arrlen)
        {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return arr[idx];
    }
    ~BoundCheckIntArray()
    {
        delete[] arr;
    }
};

int main()
{
    BoundCheckIntArray arr(5);
    for (int i = 0; i < 5; i++)
        arr[i] = (i + 1) * 11;

    BoundCheckIntArray cpy1(5);
    cpy1 = arr; // 대입 연산자 호출 막음
    BoundCheckIntArray copy = arr;  // 복사 생성자 호출 막음
    return 0;
}