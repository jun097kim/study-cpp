// 사용자가 정의한 클래스
class Point
{

};

int main()
{
    Point p1(2, 3), p2(5, 5);

    p1 + p2;    // 컴파일러는 두 객체의 연산을 알고 있지 않습니다. 에러!!

    return 0;
}