#include <iostream>
using namespace std;

int index_leftChild(int index) {
	return 2 * index + 1;
}
int index_rightChild(int index) {
	return 2 * index + 2;
}
int index_parent(int index) {
	return index > 2 ? (index - 1) / 2 : 0;
}
bool hasLeftChild(int index, int size) {
	int n = 2 * index + 1;
	return n >= size ? false : true;
}
bool hasRightChild(int index, int size) {
	int n = 2 * index + 2;
	return n >= size ? false : true;
}
void print(int array[], int size) {
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << "\n";
	}
	cout << "\n";
}
void bubbleDown(int array[], int index, int size) {
	if (!hasLeftChild(index, size) && !hasRightChild(index, size)) {
		return;
	}
	if (hasLeftChild(index, size) && !hasRightChild(index, size)) {
		if (array[index_leftChild(index)] > array[index]) {
			swap(array[index], array[index_leftChild(index)]);
		}
		return;
	}
	if (array[index_leftChild(index)] > array[index_rightChild(index)]) {
		if (array[index_leftChild(index)] > array[index])
		{
			swap(array[index], array[index_leftChild(index)]);
			bubbleDown(array, index_leftChild(index), size);
		}
	}
	else {
		if (array[index_rightChild(index)] > array[index])
		{
			swap(array[index], array[index_rightChild(index)]);
			bubbleDown(array, index_rightChild(index), size);
		}
	}
}

void Heapify(int array[], int size) {
	for (int i = index_parent(size - 1); i >= 0; --i)
	{
		bubbleDown(array, i, size);
	}	
}

void HeapSort(int array[], int size,int counter) {
	Heapify(array, size);

	for (int i = 0; i < size; i++)
	{
		swap(array[0], array[counter - 1]);
		counter--;
		bubbleDown(array, 0, counter);
	}

}
int main() {
	const int size = 20;
	int array[size];
	for (size_t i = 0; i <size; i++)
	{
		array[i] = rand() % 100 + 1;
	}

	HeapSort(array, size,size);
	print(array, size);



}