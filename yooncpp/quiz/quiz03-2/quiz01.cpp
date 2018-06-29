#include <iostream>
#include <cstdio>
using namespace std;

class Calculator {
private:
    int addCnt;
    int minCnt;
    int mulCnt;
    int divCnt;

public:
    void Init();
    double Add(double a, double b);
    double Min(double a, double b);
    double Mul(double a, double b);
    double Div(double a, double b);
    void ShowOpCount();
};

void Calculator::Init()
{
    addCnt = minCnt = mulCnt = divCnt = 0;
}

double Calculator::Add(double a, double b)
{
    addCnt++;
    return a + b;
}

double Calculator::Min(double a, double b)
{
    minCnt++;
    return a - b;
}

double Calculator::Mul(double a, double b)
{
    mulCnt++;
    return a * b;
}

double Calculator::Div(double a, double b)
{
    divCnt++;
    return a / b;
}

void Calculator::ShowOpCount()
{
    printf("덧셈: %d 뺄셈: %d 곱셈: %d 나눗셈: %d", addCnt, minCnt, mulCnt, divCnt);
}

int main()
{
    Calculator cal;
    cal.Init();
    cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
    cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
    cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
    cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
    cal.ShowOpCount();
    return 0;
}