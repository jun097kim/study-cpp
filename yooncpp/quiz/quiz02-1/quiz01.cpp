#include <iostream>
using namespace std;

void plusOne(int &);
void inverseSign(int &);

int main()
{
    int num = 5;
    
    plusOne(num);
    cout << "1 증가: " << num << endl;

    inverseSign(num);
    cout << "부호 반전: " << num << endl;

    return 0;
}

void plusOne(int &num)
{
    num += 1;
}

void inverseSign(int &num)
{
    num *= -1;
}