#include <iostream>

namespace BestComImpl
{
    void SimpleFunc();
}

namespace ProgComImpl
{
    void SimpleFunc();
}

int main()
{
    BestComImpl::SimpleFunc();
    ProgComImpl::SimpleFunc();

    return 0;
}

void BestComImpl::SimpleFunc() {
    std::cout << "BestComImpl이 정의한 함수" << std::endl;
}

void ProgComImpl::SimpleFunc() {
    std::cout << "ProgComImpl이 정의한 함수" << std::endl;
}