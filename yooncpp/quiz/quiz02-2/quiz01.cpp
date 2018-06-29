#include <iostream>
using namespace std;

int main()
{
    const int num = 12;
    const int *numPtr = &num;
    const int &numRef = num;

    cout << "num: " << num << endl;
    cout << "*numPtr: " << *numPtr << endl;
    cout << "numRef: " << numRef << endl;

    return 0;
}