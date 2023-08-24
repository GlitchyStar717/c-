#include <iostream>
using namespace std;
class Stack
{
private:
    int *arr;
    int top, size;

public:
    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(int item)
    {
        try
        {
            if (top + 1 == size)
            {
                throw "Stack is full!";
            }

            // This line is not executed if the exception is raised
            arr[++top] = item;
        }
        catch (const char *e)
        {
            // This block is executed if the above stack overflow error is raised
            cerr << "Error: " << e << '\n';
        }
    }

    int pop()
    {
        try
        {
            if (top == -1)
            {
                throw "Stack is empty!";
            }

            return arr[top--];
        }
        catch (const char *e)
        {
            cerr << "Error: " << e << '\n';
        }
    }
};

int main()
{
    Stack s(2);

    s.pop();

    s.push(1);
    s.push(7);

    s.push(4);

    return 0;
}