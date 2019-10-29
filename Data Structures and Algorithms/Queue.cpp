#include <iostream>
using namespace std;

template<class T>
struct Node {
	T data;
	Node* next = nullptr;
	Node(const T& data) :data(data) {}
};
template <class T>
class Queue {
private:
	int size = 0;
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
public:
	~Queue() {
		Node<T>* traversal = head;
		while (traversal != nullptr) {
			Node<T>* traversal2 = traversal->next;
			delete traversal;
			traversal = traversal2;
		}
		size = 0;
	}
	void enqueue(const T& data) {
		if (size == 0) {
			head = new Node<T>(data);
			tail = head;
			size++;
		}
		else {
			tail->next = new Node<T>(data);
			tail = tail->next;
			size++;
		}
	}
	void dequeue() {
		if (size == 0) return;
		if (size == 1) {
			delete head;
			head = nullptr;
			tail = nullptr;
			size = 0;
		}
		else {
			Node<T>* temp = head->next;
			delete head;
			head = temp;
			size--;
		}
	}
	void print() {
		Node<T>* traversal = head;
		while (traversal != nullptr) {
			cout << "--> " << traversal->data << "\n";
			traversal = traversal->next;
		}
	}
};

int main() {
	Queue<int> test;
	test.enqueue(1);
	test.enqueue(2);
	test.enqueue(3);
	test.enqueue(4);
	test.print();
	cout << "----dequeued----\n";
	test.dequeue();
	test.print();
}