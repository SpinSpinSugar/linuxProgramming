#pragma once
#include <ostream>

class LinkedList {
private:
	struct Node {
		int _Data;
		Node* _Next;
		Node(int x) : _Data(x), _Next(nullptr) {};
		friend std::ostream& operator<<(std::ostream& stream, const Node& node) {
			stream << node._Data;
			return stream;
		}
	};
	Node* _Begin; //first element
	Node* _End; //last element

public:
	LinkedList() : _Begin(nullptr), _End(nullptr) {};
	int& front();
	int& back();
	void push_front(const int& value);
	void push_back(const int& value);
	friend std::ostream& operator<<(std::ostream& stream, const LinkedList& list);friend std::ostream& operator<<(std::ostream& stream, const LinkedList& list);
	
	//HOMEWORK
	void insert(const int& position, const int& value); //numeration [0...n]
	void erase(const int& position);
	void swap(const int& position1, const int& position2);
};