#include <iostream>
using namespace std;

template <typename T>
class Queue
{
    T *buf;
    int front, rear;

  public:
    Queue()
    {
        buf = new T[50];
        front = rear = 0;
    }

    void Push(T data)
    {
        buf[rear++] = data;
    }
    const T &Pop()
    {
        return buf[front++];
    }
    bool Empty() const
    {
        return front == rear;
    }
};

int main()
{
    Queue<int> q;

    q.Push(10);
    q.Push(20);
    q.Push(30);

    if (!q.Empty())
        cout << q.Pop() << endl; // 10
    if (!q.Empty())
        cout << q.Pop() << endl; // 20
    if (!q.Empty())
        cout << q.Pop() << endl; // 30

    return 0;
}