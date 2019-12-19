#include <iostream>

using namespace std;

void print(int array[], int size) {
	for (size_t i = 0; i < size; i++)
	{
		cout << "--> " << array[i] << endl;
	}
}
void Merge(int array[], int left, int middle, int right) {
	int* temp = new int[left + right + 1];
	int leftIndex = left;
	int rightIndex = middle + 1;
	int index = 0;


	while (leftIndex <= middle && rightIndex <= right) {
		if (array[leftIndex] > array[rightIndex]) {
			temp[index++] = array[rightIndex++];
		}
		else {
			temp[index++] = array[leftIndex++];
		}
	}

	while (leftIndex <= middle) {
		temp[index++] = array[leftIndex++];
	}
	while (rightIndex <= right) {
		temp[index++] = array[rightIndex++];
	}

	for (int i = left; i <= right; i++)
	{
		array[i] = temp[i - left];
	}
}

void MergeSort(int array[], int left, int right) {
	if (left < right) {
		int middle = (left + right) / 2;
		MergeSort(array, left, middle);
		MergeSort(array, middle + 1, right);
		Merge(array, left, middle, right);
	}
}


int main() {
	const int size = 20;
	int array[size];
	for (size_t i = 0; i < size; i++)
	{
		array[i] = rand() % 100 + 1;
	}

	MergeSort(array, 0, size-1);
	print(array, size);
}