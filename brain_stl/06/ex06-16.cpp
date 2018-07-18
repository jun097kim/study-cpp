#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v(5, 1); // 초깃값 1의 5개의 원소를 갖는 컨테이너 생성

    for (vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;

    v.assign(3, 2); // 5개의 원소값을 2로 할당

    for (vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;

    return 0;
}