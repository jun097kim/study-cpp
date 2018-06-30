#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;

public:
    Point(int x, int y)
        :xpos(x), ypos(y)
    {
    }
    void ShowPointInfo() const
    {
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    }
};

class Circle
{
    Point center;
    int radius;

public:
    Circle(int x, int y, int r)
        :center(x, y), radius(r)
    {
    }

    void ShowCircleInfo() const
    {
        cout << "radius: " << radius << endl;
        center.ShowPointInfo();
    }
};

class Ring
{
    Circle inner;
    Circle outer;

public:
    Ring(int x1, int y1, int r1, int x2, int y2, int r2)
        :inner(x1, y1, r1), outer(x2, y2, r2)
    {
    }
    void ShowRingInfo() const
    {
        cout << "Inner Circle Info..." << endl;
        inner.ShowCircleInfo();
        cout << "Outer Circle Info..." << endl;
        outer.ShowCircleInfo();
    }
};

int main()
{
    Ring ring(1, 1, 4, 2, 2, 9);
    ring.ShowRingInfo();
    return 0;
}