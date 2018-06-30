#include <iostream>
using namespace std;

class ContryArea
{
public:
    const static int RUSSIA = 1707540;
    const static int CANADA = 998467;
    const static int CHINA = 957290;
    const static int SOUTH_KOREA = 9922;
};

int main()
{
    cout << "러시아 면적: " << ContryArea::RUSSIA << "㎢" << endl;
    cout << "캐나다 면적: " << ContryArea::CANADA << "㎢" << endl;
    cout << "중국 면적: " << ContryArea::CHINA << "㎢" << endl;
    cout << "한국 면적: " << ContryArea::SOUTH_KOREA << "㎢" << endl;
}