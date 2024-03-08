// vector.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include<vector>

using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::out_of_range;
using std::cerr;

void outputVector(const vector<int>&);
void inputVector(vector<int>&);

int main()
{
    vector<int> vector1(7);
    vector<int> vector2(10);

    cout << "Size of vector1: " << vector1.size()<<endl;
    cout << "vector after initialization: ";
    outputVector(vector1);

    cout << "Size of vector2: " << vector2.size() << endl;
    cout << "vector after initialization: ";
    outputVector(vector2);

    cout << "\nEnter 17 integers:" << endl;
    inputVector(vector1);
    inputVector(vector2);

    cout << "vector1 after input: ";
    outputVector(vector1);
    cout << "vector2 after input: ";
    outputVector(vector2);
    
    cout << "\nEvaluating vector1 and vector2:" << endl;
    if (vector1 != vector2) cout << "vector1 and vector2 are not equal" << endl;

    vector<int>vector3{ vector1 };
    cout << "\nSize of vector3: " << vector3.size() << endl;
    cout << "vector3 after initialization: ";
    outputVector(vector3);

    cout << "\nAssign vector2 to vector1:" << endl;
    vector1 = vector2;

    cout << "vector1: ";
    outputVector(vector1);

    cout << "vector2: ";
    outputVector(vector2);

    cout << "\nEvaluating vector1 and vector2:" << endl;
    if (vector1 == vector2) cout << "vector1 and vector2 are equal" << endl;

    cout << "\nvector1[5] is: " << vector1[5];

    cout << "\nAssign 1000 to vector1[5]" << endl;
    vector1[5] = 1000;
    cout << "vector1: ";
    outputVector(vector1);
    
    try {
        cout << "Attempt to display vector1.at(15)" << endl;
        cout << vector1.at(15) << endl;
    }
    catch (out_of_range& ex) { cerr << "an exception occurred: " << ex.what() << endl; }

    cout << "\nSize of vector3: " << vector3.size() << endl;
    cout << "Add 1000 to vector3" << endl;
    vector3.push_back(1000);
    cout<< "New size of vector3: " << vector3.size() << endl;
    cout << "vector3: ";
    outputVector(vector3);
}

void outputVector(const vector<int>& a) {
    for (int elements : a) {
        cout << elements << " ";
    }
    cout << endl;
}

void inputVector(vector<int>& a) {
    for (int& elements : a) {
        cin >> elements;
    }
};