#include <iostream>
using namespace std;

template <class T>
void SwapData(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

class Point
{
private:
    int xpos, ypos;

public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y)
    { }
    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
};

int main()
{
    Point p1(1, 2);
    Point p2(3, 4);
    SwapData<Point>(p1, p2);
    p1.ShowPosition();
    p2.ShowPosition();
}