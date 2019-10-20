#include<iostream>
using namespace std;
template<class T>
struct Node {
	T data;
	Node<T>* next;
	
	Node(T data) :data(data)
	{
		next = nullptr;
	}
};
template<class T>
class LinkedList {
	int size;
	Node<T>* head;
public:
	LinkedList()
	{
		size = 0;
		head = nullptr;
	}
	~LinkedList()
	{
		Node<T>* ptr = head;
		while (ptr != nullptr) {
			Node<T>* ptr2 = ptr->next;
			delete ptr;
			ptr = ptr2;
		}
		size = 0;
	}
	bool ifEmpty(T data) {
		if (size == 0) {
			head = new Node<T>(data);
			size++;
			return true;
		}
		return false;
	}
	void pushBack(T data) {
		if(!ifEmpty(data))
		{
			Node<T>* traversal=head;
			while (traversal->next != nullptr) {
				traversal = traversal->next;
			}
			Node<T>* newNode = new Node<T>(data);
			traversal->next = newNode;
			size++;
		}
	}
	void pushFront(T data) {
		if (!ifEmpty(data)) {
			Node<T>* newNode = new Node<T>(data);
			newNode->next = head;
			head = newNode;
			size++;
		}
	}
	void popBack() {
		if (size <= 0) return;
		if (size == 1) {
			delete head;
			head = nullptr;
			size = 0;
			return;
		}
		Node<T>* traversal = head;
		Node<T>* traversal2 = head->next;
		while (traversal2->next != nullptr) {
			traversal = traversal2;
			traversal2 = traversal2->next;
		}
		delete traversal2;
		traversal->next = nullptr;
		size--;
	}
	void popFront() {
		if (size <= 0) return;
		if (size == 1) {
			delete head;
			head = nullptr;
			size = 0;
			return;
		}
		Node<T>* temp = head->next;
		delete head;
		head = temp;
		size--;
	}
	void addToIndex(T data, int index) {
		if (index > size) return;
		if (size == index) { pushBack(data); return; }
		if (index == 0) {
			pushFront(data);
			return;
		}
		int counter = 0;
		Node<T>* before=head;
		Node<T>* after=before->next;
		while (counter!=index-1)
		{
			before = after;
			after = before->next;
			counter++;
		}
		Node<T>* newNode = new Node<T>(data);
		newNode->next = after;
		before->next = newNode;
		size++;
	}
	void removeFromIndex(int index) {
		if (index > size) return;
		if (index == size) {
			popBack(); return;
		}
		if (index == 0) { popFront(); return; }
		int counter = 0;
		Node<T>* before = head;
		Node<T>* after = before->next;
		while (counter != index - 1) {
			before = after;
			after = before->next;
			counter++;
		}
		before->next = after->next;
		delete after;
		after = nullptr;
		size--;
	}
	void Print() {
		Node<T>* traversal = head;
		while (traversal != nullptr)
		{
			cout << "--> " << traversal->data << "\n";
			traversal = traversal->next;
		}
	}
};
int main() {
	LinkedList<int> test;
	test.pushBack(1);
	test.pushBack(2);
	test.pushBack(3);
	test.pushBack(4);
	test.Print();
	test.addToIndex(1337, 3);
	cout << "-----added to index 4-----\n";
	test.Print();
	test.addToIndex(1338, 2);
	cout << "-----added to index 2-----\n";
	test.Print();
	cout << "----popped back----\n";
	test.popBack();
	test.Print();
	cout << "----popped front----\n";
	test.popFront();
	test.Print();
	cout << "----removed from index 2----\n";
	test.removeFromIndex(2);
	test.Print();
	
}