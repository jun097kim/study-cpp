#include <iostream>
using namespace std;

typedef struct __Point
{
    int xpos;
    int ypos;
} Point;

Point& PntAdder(const Point &p1, const Point &p2);

int main()
{
    Point *pptr1 = new Point;
    pptr1->xpos = 2;
    pptr1->ypos = 4;

    Point *pptr2 = new Point;
    pptr2->xpos = 6;
    pptr2->ypos = 2;

    Point &pref = PntAdder(*pptr1, *pptr2);
    cout << "[" << pref.xpos << ", " << pref.ypos << "]" << endl;

    delete pptr1;
    delete pptr2;
    delete &pref;

    return 0;
}

Point& PntAdder(const Point &p1, const Point &p2)
{
    Point *pptr = new Point;
    pptr->xpos = p1.xpos + p2.xpos;
    pptr->ypos = p1.ypos + p2.ypos;
    return *pptr;
}