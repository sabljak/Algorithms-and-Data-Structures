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
	void addToIndex(int index,const T& data) {
		if (index<0 || index>size) {
			return;
		}
		if (index == size) {
			pushBack(data); return;
		}
		if (index == 0) {
			pushFront(data); return;
		}
		int counter = 0;
		Node<T>* newNode = new Node<T>(data);
		Node<T>* temp = head;
		while (counter != index - 1) {
			temp = temp->next;
			counter++;
		}
		Node<T>* tempNext = temp->next;
		temp->next = newNode;
		newNode->previous = temp;
		newNode->next = tempNext;
		size++;
		return;	
	}
	void removeFromIndex(int index) {
		if (index < 0 || index >= size) {
			return;
		}
		if (index == 0) {
			popFront();
			return;
		}
		if (index == size - 1) {
			popBack(); return;
		}
		Node<T>* temp = head;
		int counter = 0;
		while (counter != index) {
			temp = temp->next;
			counter++;
		}
		Node<T>* tempNext = temp->next;
		temp->previous->next = tempNext;
		tempNext->previous = temp->previous;
		delete temp;
		temp = nullptr;
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
	test.pushBack(5);
	test.pushFront(6);
	test.print();
	cout << "-----popback--------\n";
	test.popBack();
	test.print();
	cout << "-----popfront--------\n";
	test.popFront();
	test.print();
	cout << "----added to index 2---\n";
	test.addToIndex(2, 1337);
	test.print();
	test.removeFromIndex(2);
	cout << "----removed from index 2---\n";
	test.print();
}