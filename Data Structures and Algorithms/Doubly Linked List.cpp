#include <iostream>
using namespace std;

template<class T>
struct Node {
	T data;
	Node<T>* previous=nullptr;
	Node<T>* next = nullptr;
	Node(const T& data):data(data){}
	
};
template<class T>
class DoublyLinkedList {
private:
	int size;
	Node<T>* head=nullptr;
public:
	DoublyLinkedList():size(0){}
	~DoublyLinkedList()
	{
		Node<T>* ptr = head; 
		while (ptr != nullptr) {
		Node<T>* ptr2 = ptr->next;
			delete ptr;
			ptr = ptr2;
		}
		size = 0;
	}
	void pushBack(const T& data) {
		if (size == 0) {
			head = new Node<T>(data);
			size++;
			return;
		}
		Node<T>* traversal = head;
		while (traversal->next != nullptr) {
			traversal = traversal->next;
		}
		Node<T>* newNode = new Node<T>(data);
		newNode->previous = traversal;
		traversal->next = newNode;
		size++;
	}
	void pushFront(const T& data) {
		if (size == 0) {
			head = new Node<T>(data);
			size++;
			return;
		}
		Node<T>* newNode = new Node<T>(data);
		newNode->next = head;
		head->previous = newNode;
		head = newNode;
		size++;
	}
	void popBack() {
		if (size == 1) { delete head; head = nullptr; size--; return; }
		Node<T>* traversal = head;
		while (traversal->next!=nullptr)
		{
			traversal = traversal->next;
		}
		traversal->previous->next = nullptr;
		delete traversal;
		size--;
	}
	void popFront() {
		if (size == 1) { delete head; head = nullptr; size--; return;}
		head = head->next;
		delete head->previous;
		head->previous = nullptr;
		size--;
	}
	void print() {
		Node<T>* traversal = head;
			while (traversal != nullptr) {
				cout << "--> " << traversal->data<<"\n";
				traversal = traversal->next;
			}
	}

};

int main() {
	DoublyLinkedList<int> test;
	test.pushBack(1);
	test.pushBack(2);
	test.pushBack(3);
	test.pushBack(4);
	test.print();
	cout << "-----popback--------\n";
	test.popBack();
	test.print();
	cout << "-----popfront--------\n";
	test.popFront();
	test.print();
}