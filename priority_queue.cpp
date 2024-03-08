// priority_queue.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include<queue>
#include <iostream>

using std::priority_queue;
using std::cout;
using std::endl;

int main()
{
    priority_queue<double> priorities;

    priorities.push(3.2);
    priorities.push(9.8);
    priorities.push(5.4);

    cout << "Popping from priorities: ";

    while (!priorities.empty()) {
        cout << priorities.top() << " ";
        priorities.pop();
    }

    cout << endl;
}
 
