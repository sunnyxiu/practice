// Queue_from list.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include"Queue.h"

using std::cout;
using std::endl;

int main()
{
    Queue<int> intQueue;

    cout << "processing an integer Queue" << endl;

    for (int i{ 0 }; i < 3; i++) {
        intQueue.enqueue(i);
        intQueue.printQueue();
    }

    int dequeueInteger;

    while (!intQueue.isQueueEmpty()) {
        intQueue.dequeue(dequeueInteger);
        cout << dequeueInteger << " dequeued" << endl;
        intQueue.printQueue();
    }

    Queue<double> doubleQueue;

    cout << "processing an double Queue" << endl;

    double value{ 1.1 };

    for (int i{ 0 }; i < 3; i++) {
        doubleQueue.enqueue(value);
        doubleQueue.printQueue();
        value += 1.1;
    }

    double dequeueDouble;

    while (!doubleQueue.isQueueEmpty()) {
        doubleQueue.dequeue(dequeueDouble);
        cout << dequeueDouble << " dequeued" << endl;
        doubleQueue.printQueue();
    }

    
}


