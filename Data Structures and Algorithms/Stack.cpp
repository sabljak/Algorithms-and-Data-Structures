#include<iostream>	
using namespace std;

template<class T>
struct Node {
	T data;
	Node<T>* previous;
	Node(const T& data):data(data)
	{
		previous = nullptr;
	}
};
template<class T>
class Stack {
private:
	Node<T>* top;
public:
	Stack():top(nullptr){}
	~Stack()
	{
		Node<T>* traversal = top;
		while (traversal != nullptr) {
			Node<T>* traversal2 = traversal->previous;
			delete traversal;
			traversal = traversal2;
		}
	}
	void push(const T& data) {
		if (top == nullptr) {
			top = new Node<T>(data);
			top->previous = nullptr;
		}
		else {
			Node<T>* newNode = new Node<T>(data);
			newNode->previous = top;
			top = newNode;
		}

	}
	void pop() {
		if (top == nullptr) {
			return;
		}

		if (top->previous == nullptr) {
			delete top;
			top = nullptr;
			return;
		}

		Node<T>* temp = top->previous;
		delete top;
		top = temp;
	}
	void print() {
		if (top != nullptr) {
			Node<T>* ptr = top;
			while (ptr != nullptr)
			{
				cout << "--> " << ptr->data << "\n";
				ptr = ptr->previous;
			}
		}
	}
};
int main() {
	Stack<int> test;
	test.push(1);
	test.push(2);
	test.push(3);
	test.push(4);
	test.pop();
	test.push(4);
	test.print();
}