#include <iostream>

namespace BestComImpl
{
    void SimpleFunc();
}

namespace BestComImpl
{
    void PrettyFunc();
}

namespace ProgComImpl
{
    void SimpleFunc();
}

int main()
{
    BestComImpl::SimpleFunc();
    return 0;
}

void BestComImpl::SimpleFunc()
{
    std::cout << "BestComImpl이 정의한 함수" << std::endl;
    PrettyFunc();   // 동일 이름공간
    ProgComImpl::SimpleFunc();  // 다른 이름공간
}

void BestComImpl::PrettyFunc()
{
    std::cout << "So Pretty!!" << std::endl;
}

void ProgComImpl::SimpleFunc() {
    std::cout << "ProgComImpl이 정의한 함수" << std::endl;
}