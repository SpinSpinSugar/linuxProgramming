#include "LinkedList.h"

std::ostream& operator<<(std::ostream& stream, const LinkedList& list) {
	LinkedList::Node* temp = list._Begin;
	if (temp == nullptr) return stream << "Empty List";
	while (temp != nullptr)
	{
		stream << *temp << " ";
		//stream << temp->_Data << " ";
		temp = temp->_Next;
	}
	return stream;
}

int& LinkedList::front() {
	if (_Begin == nullptr) throw;
	return _Begin->_Data;
}

int& LinkedList::back() {
	if (_End == nullptr) throw;
	return _End->_Data;
}

void LinkedList::push_front(const int& value) {
	
	Node* newNode = new Node(value);
	newNode->_Next = _Begin;
	_Begin = newNode;
	if (_End == nullptr) {
		_End = _Begin;
	}
}

void LinkedList::push_back(const int& value) {
	if (_Begin == nullptr) {
		push_front(value);
		return;
	}

	Node* newNode = new Node(value);
	_End->_Next = newNode;
	_End = newNode;
}

//HOMEWORK
void LinkedList::insert(const int& position, const int& value) {
	Node* newNode = new Node(value);
	Node* temp  = _Begin;
	for (int i = 0; i < position - 1; ++i) {
		if (temp == nullptr) return;
		temp = temp->_Next;
	}
	newNode->_Next = temp->_Next;
	temp->_Next = newNode;
}

void LinkedList::erase(const int& position) {
	Node* temp = _Begin;
	for (int i = 0; i < position - 1; ++i) {
		temp = temp->_Next;
		if (temp->_Next == nullptr) return;
	}
	Node* nodeToErase = temp->_Next;
	temp->_Next = nodeToErase->_Next;
	delete nodeToErase;
}

void LinkedList::swap(const int& position1, const int& position2) {
	Node* temp1  = _Begin;
	Node* temp2  = _Begin;
	for (int i = 0; i < std::max(position1, position2) - 1; ++i) {
		if (temp1->_Next == nullptr || temp2->_Next == nullptr) return;
		if (i < position1) temp1 = temp1->_Next;
		if (i < position2) temp2 = temp2->_Next;
	}
	std::swap(temp1->_Data, temp2->_Data);
}