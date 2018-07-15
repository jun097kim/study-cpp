#include <iostream>
using namespace std;

class MyType
{
};

template <typename T>
void Copy(T t, T s, int n)
{
    for (int i = 0; i < n; i++)
        t[i] = s[i];
}

int main()
{
    int arr1[5] = {10, 20, 30, 40, 50};
    int arr2[5];

    // Copy(t, s, n) t:목적지 주소, s:소스 주소, n: 원소 개수
    Copy(arr2, arr1, 5);

    MyType myArr1[5];
    MyType myArr2[5];
    Copy(myArr2, myArr1, 5);

    return 0;
}