#include <iostream>
#include <vector>
using namespace std;

template<class T>
struct Node {
	T data;
	int priority;
	Node(const T& data,int priority):data(data),priority(priority){}
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
		return index > 2 ? (index - 1) / 2: 0;
	} 
	bool hasLeftChild(int index) {
		int n = 2 * index + 1;
		
			return n >=items.size() ? false : true;
		
		
	}
	bool hasRightChild(int index) {
		int n = 2 * index + 2;
		return n >= items.size() ? false : true;
	}

	void bubbleUp(int index) {
		if (items.size() == 1) {
			return;
		}
		while (items[index].priority < items[index_parent(index)].priority) {
			swap(items[index], items[index_parent(index)]);
			index = index_parent(index);
		}

	}
	void enqueue(const T& data, int priority) {
		items.push_back(Node<T>(data,priority));
		bubbleUp(items.size()-1);
	}
	void print() {
		for (int i = 0; i < items.size(); i++)
		{
			cout << items[i].data<<" - "<<items[i].priority << endl;
		}
	}
	void bubbleDown() {
		int index = 0;
		//if (items.size() <= 2) return;
		
		/*while (items[index].priority > items[index_leftChild(index)].priority
			||
			items[index].priority > items[index_rightChild(index)].priority) {

			if (items[index_leftChild(index)].priority < items[index_rightChild(index)].priority) {

				swap(items[index], items[index_leftChild(index)]);
				index = index_leftChild(index);
			}
			else {
				swap(items[index], items[index_rightChild(index)]);
				index = index_rightChild(index);
			}
			if (index_leftChild(index) >= items.size() || index_rightChild(index) >= items.size()) {
				break;
			}
		}*/
		while (hasLeftChild(index)) {
			int smallest = items[index_leftChild(index)].priority;
			if (hasRightChild(index)) {
				if (smallest > items[index_rightChild(index)].priority) {
					//ako ima desno zamijeni

					smallest = items[index_rightChild(index)].priority;
					swap(items[index], items[index_rightChild(index)]);
					index = index_rightChild(index);

				}
				else {
					swap(items[index], items[index_leftChild(index)]);
					index = index_leftChild(index);
				}
			}
			else {
				if (items[index].priority > items[index_leftChild(index)].priority) {
					swap(items[index], items[index_leftChild(index)]);
					index = index_leftChild(index);
				}
				else {
					break;
				}
			}
		}
		

	}
	void dequeue() {
		if (!items.empty()) {
			items[0] = items[items.size() - 1];

			items.pop_back();
			bubbleDown();
		}
		
	}
};

int main() {

	PQHeap<int> test;
	test.enqueue(30,2);
	test.enqueue(20,1);
	test.enqueue(50,0);
	test.enqueue(40, 5);
	test.enqueue(10,2);
	test.enqueue(60,3);
	test.print();
	cout << endl;
	test.dequeue();
	test.print();
	cout << endl;
	test.dequeue();
	test.print();
	cout << endl;
	test.dequeue();
	test.print();
	cout << endl;
	test.dequeue();
	test.print();
	cout << endl;
	test.dequeue();
	test.print();
	cout << endl;
	test.dequeue();
	test.print();
	
}