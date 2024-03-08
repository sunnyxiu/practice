#ifndef QUEUE_H
#define QUEUE_H

#include"List.h"

template<typename QUEUETYPE>
class Queue:private List<QUEUETYPE> {
public:
	
	void enqueue(const QUEUETYPE& value) {
		listObject.insertAtBack(value);
	}

	bool dequeue(QUEUETYPE& value) {
		return listObject.removeFromFront(value);
	}

	bool isQueueEmpty() const{
		return listObject.isEmpty();
	}
	
	void printQueue()const {
		listObject.print();
	}

private:
	List<QUEUETYPE> listObject;
};


#endif
