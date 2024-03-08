#ifndef LIST_H
#define LIST_H
#include"ListNode.h"
#include<iostream>

using std::cout;
using std::endl;

template<typename NODETYPE>
class List {
public:
	~List() {
		if (!isEmpty()) {
			cout << "Destroying nodes...\n";

			ListNode<NODETYPE>* currentPtr{ firstPtr };
			ListNode<NODETYPE>* tempPtr{ nullptr };

			while (currentPtr != nullptr) {
				tempPtr = currentPtr;
				cout << tempPtr->getData() << endl;
				currentPtr = tempPtr->nextPtr;
				delete tempPtr;
			}
		}
		
		cout << "All nodes destroyed\n\n";
	};

	void insertAtFront(const NODETYPE& value) {
		ListNode<NODETYPE>* newPtr{ getNewNode(value) };
		
		if (isEmpty()) {
			firstPtr = lastPtr = newPtr;
		}
		else {
			newPtr->nextPtr = firstPtr;
			firstPtr = newPtr;
		}
	}

	void insertAtBack(const NODETYPE& value) {
		ListNode<NODETYPE>* newPtr{ getNewNode(value) };

		if (isEmpty()) {
			firstPtr = lastPtr = newPtr;
		}
		else {
			lastPtr->nextPtr = newPtr;
			lastPtr = newPtr;
		}
	}

	bool removeFromFront(NODETYPE& value) {
		if (isEmpty()) {
			return false;
		}
		else{
			ListNode<NODETYPE>* tempPtr{ firstPtr };

			if (firstPtr == lastPtr) {
				firstPtr = lastPtr = nullptr;
			}
			else {
				firstPtr = firstPtr->nextPtr;
			}

			value = tempPtr->getData();//??????
			delete tempPtr;
			return true;
		}
	}

	bool removeFromBack(NODETYPE& value) {
		if (isEmpty()) {
			return false;
		}
		else {
			ListNode<NODETYPE>* tempPtr{ lastPtr };
			
			if (firstPtr == lastPtr) {
				firstPtr = lastPtr = nullptr;
			}
			else {
				ListNode<NODETYPE>* currentPtr{ firstPtr };

				while (currentPtr->nextPtr != lastPtr) {
					currentPtr = currentPtr->nextPtr;
				}

				lastPtr = currentPtr;
				currentPtr->nextPtr = nullptr;
			}

			value = tempPtr->getData();
			delete tempPtr;
			return true;
		}
	}

	bool isEmpty() const{
		return (firstPtr == nullptr);
	};
	
	void print() const{
		if (isEmpty()) {
			cout << "The list is empty\n\n";
			return;
		}

		ListNode<NODETYPE>* currentPtr{ firstPtr };

		cout << "The list is: ";

		while (currentPtr != nullptr) {
			cout << currentPtr->getData()<<" ";
			currentPtr = currentPtr->nextPtr;
		}

		cout << "\n\n";
	}
private:
	ListNode<NODETYPE>* firstPtr;
	ListNode<NODETYPE>* lastPtr;
	ListNode<NODETYPE>* getNewNode(const NODETYPE& value) {
		return new ListNode<NODETYPE>{ value };
	}
};



#endif // !LIST_H

