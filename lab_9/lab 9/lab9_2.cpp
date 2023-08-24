#include <iostream>
#include <queue>

using namespace std;

template <typename T>
class Queue {
private:
    queue<T> q;

public:
    void enqueue(T item) {
        q.push(item);
    }

    T dequeue() {
        T item = q.back();
        q.pop();
        return item;
    }

    size_t size() const {
        return q.size();
    }

    bool isEmpty() const {
        return q.empty();
    }
};

int main() {
    Queue<int> intQueue;
    Queue<double> doubleQueue;
    Queue<string> stringQueue;

    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);
    intQueue.enqueue(40);

    doubleQueue.enqueue(1.1);
    doubleQueue.enqueue(2.2);

    stringQueue.enqueue("Hello");
    stringQueue.enqueue("World");

    cout << "Int Queue Size: " << intQueue.size() << endl;
    cout << "Dequeued from Int Queue: " << intQueue.dequeue() << endl;
    cout << "Int Queue Size after Dequeue: " << intQueue.size() << endl;

    cout << "Double Queue Size: " << doubleQueue.size() << endl;
    cout << "Dequeued from Double Queue: " << doubleQueue.dequeue() << endl;
    cout << "Double Queue Size after Dequeue: " << doubleQueue.size() << endl;

    cout << "String Queue Size: " << stringQueue.size() << endl;
    cout << "Dequeued from String Queue: " << stringQueue.dequeue() << endl;
    cout << "String Queue Size after Dequeue: " << stringQueue.size() << endl;

    return 0;
}
