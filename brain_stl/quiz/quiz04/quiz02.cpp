#include <iostream>
using namespace std;

template <typename T>
class Stack
{
    T *buf;
    int top;

  public:
    Stack() : top(-1)
    {
        buf = new T[50];
    }
    ~Stack()
    {
        delete[] buf;
    }
    void Push(T data)
    {
        buf[++top] = data;
    }
    const T &Pop()
    {
        return buf[top--];
    }
    bool Empty() const
    {
        return top == -1;
    }
};

int main()
{
    Stack<int> st;

    st.Push(10);
    st.Push(20);
    st.Push(30);

    if (!st.Empty())
        cout << st.Pop() << endl; // 30
    if (!st.Empty())
        cout << st.Pop() << endl; // 20
    if (!st.Empty())
        cout << st.Pop() << endl; // 10

    return 0;
}