#include<iostream>	
using namespace std;
template<class T>
void InsertionSort(T array[], const int& size) {

	for (int i = 1; i < size; i++)
	{
		if (array[i] < array[i - 1]) {
			int j = i;
			while (array[j] < array[j - 1])
			{
				swap(array[j], array[j - 1]);
				j--;
				if (j == 0) break;
			}
		}
	}
}
template<class T>
void Print(T array[], int size) {
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
	InsertionSort(array, size);
	Print(array, size);
}