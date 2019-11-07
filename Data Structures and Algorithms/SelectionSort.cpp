#include<iostream>	
using namespace std;
template<class T>
void SelectionSort(T array[], const int& size) {
	int min_index;
	for (int i = 0; i < size; i++)
	{
		min_index = i;
		for (int j = i; j < size; j++)
		{
			if (array[j] < array[min_index]) {
				min_index = j;
			}
		}
		swap(array[i], array[min_index]);
	}
}
template<class T>
void Print(T array[],const int& size) {
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << "\n";
	}
}

int main() {
	const int size = 15;
	int array[size];
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 100 + 1;
	}
	Print(array, size);
	cout << endl;
	SelectionSort(array, size);
	Print(array, size);
}