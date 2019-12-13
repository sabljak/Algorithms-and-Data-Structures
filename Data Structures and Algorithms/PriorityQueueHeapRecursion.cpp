#include <iostream>
#include <vector>
using namespace std;

template<class T>
struct Node {
	T data;
	int priority;
	Node(const T& data, int priority) :data(data), priority(priority) {}
};
template<class T>
class PQHeap {
	vector<Node<T>> items;
public:
	int index_leftChild(int index) {
		return 2 * index + 1;
	}
	int index_rightChild(int index) {
		return 2 * index + 2;
	}
	int index_parent(int index) {
		return index > 2 ? (index - 1) / 2 : 0;
	}
	bool hasLeftChild(int index) {
		int n = 2 * index + 1;
		return n >= items.size() ? false : true;
	}
	bool hasRightChild(int index) {
		int n = 2 * index + 2;
		return n >= items.size() ? false : true;
	}
	void bubbleUp(int index) {
		if (items.size() == 1) return;
		if (items[index].priority <= items[index_parent(index)].priority)
			return;

		swap(items[index], items[index_parent(index)]);
		bubbleUp(index_parent(index));
	}
	int getRightChildPriority(int index) {
		return items[index_rightChild(index)].priority;
	}
	int getLeftChildPriority(int index) {
		return items[index_leftChild(index)].priority;
	}
	void enqueue(const T& data, int priority) {
		items.push_back(Node<T>(data, priority));
		bubbleUp(items.size() - 1);
	}
	void print() {
		for (int i = 0; i < items.size(); i++)
		{
			cout << items[i].data << " - " << items[i].priority << "\n";
		}
		cout << "\n";
	}
	void bubbleDown(int index) {
		if (!hasLeftChild(index) || !hasRightChild(index)) {
			return;
		}
		if (getLeftChildPriority(index) > getRightChildPriority(index)) {
			if (getLeftChildPriority(index) > (items[index].priority))
			{
				swap(items[index], items[index_leftChild(index)]);
				bubbleDown(index_leftChild(index));
			}
		}
		else {
			if (getRightChildPriority(index) > items[index].priority)
			{
				swap(items[index], items[index_rightChild(index)]);
				bubbleDown(index_leftChild(index));
			}
		}
	}
	void dequeue() {
		if (!items.empty()) {
			items[0] = items[items.size() - 1];
			items.pop_back();
			bubbleDown(0);
		}
		else {
			cout << "\nAll items removed\n";
		}
	}
};

int main() {

	PQHeap<int> test;
	test.enqueue(30, 2);
	test.enqueue(20, 1);
	test.enqueue(50, 0);
	test.enqueue(40, 5);
	test.enqueue(10, 2);
	test.enqueue(60, 3);
	test.print();
	test.dequeue();
	test.print();
	test.dequeue();
	test.print();
	test.dequeue();
	test.print();
	test.dequeue();
	test.print();
	test.dequeue();
	test.print();
	test.dequeue();
	test.print();
	test.dequeue();
	test.print();

}