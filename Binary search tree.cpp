// Binary search tree.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include<iomanip>
#include <iostream>
#include"Tree.h"

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

int main()
{
    Tree<int> intTree;

    cout << "Enter 10 integer values:\n";

    for (int i{ 0 }; i < 10; i++) {
        int intValue{ 0 };
        cin >> intValue;
        intTree.insertNode(intValue);
    }

    cout << "\nPreorder traversal\n";
    intTree.preOrderTraversal();
    
    cout << "\nInorder traversal\n";
    intTree.inOrderTraversal();

    cout << "\nPostorder traversal\n";
    intTree.postOrderTraversal();

    Tree<double> doubleTree;
    cout << "\nEnter 10 double values\n";

    for (int i{ 0 }; i < 10; i++) {
        double doubleValue{ 0.0 };
        cin >> doubleValue;
        doubleTree.insertNode(doubleValue);
    }

    cout << fixed << setprecision(1);

    cout << "\nPreorder traversal\n";
    doubleTree.preOrderTraversal();

    cout << "\nInorder traversal\n";
    doubleTree.inOrderTraversal();

    cout << "\nPostorder traversal\n";
    doubleTree.postOrderTraversal();
    cout << endl;
}


