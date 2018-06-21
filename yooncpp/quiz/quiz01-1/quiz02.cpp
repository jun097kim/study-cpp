#include <iostream>

int main()
{
    char name[100];
    char phone[100];

    std::cout << "이름과 전화번호 입력: ";
    std::cin >> name >> phone;
    std::cout << "이름: " << name << ", 전화번호: " << phone;

    return 0;
}