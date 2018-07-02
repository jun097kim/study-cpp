#include <iostream>
using namespace std;

template <typename T>
class SimpleStaticMem
{
private:
    static T mem;

public:
    void AddMem(int num) { mem += num; }
    void ShowMem() { cout << mem << endl; }
};

template <typename T>
T SimpleStaticMem<T>::mem = 0;  // static 멤버 초기화

template <>
long SimpleStaticMem<long>::mem = 5;    // static 멤버변수 초기화의 특수화

int main()
{
    SimpleStaticMem<int> obj1;
    SimpleStaticMem<int> obj2;
    obj1.AddMem(2);
    obj2.AddMem(3);
    obj1.ShowMem();
    SimpleStaticMem<long> obj3;
    SimpleStaticMem<long> obj4;
    obj3.AddMem(100);
    obj4.ShowMem();
    return 0;
}