#include <iostream>

int main()
{
    int sale;

    while (true)
    {
        std::cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
        std::cin >> sale;
        if (sale == -1) break;
        int salary = 50 + (sale * 0.12);
        std::cout << "이번 달 급여: " << salary << "만원" << std::endl;
    }

    std::cout << "프로그램을 종료합니다.";
    return 0;
}