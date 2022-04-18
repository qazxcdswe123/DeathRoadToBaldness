#include <iostream>

using namespace std;

// use heap[0] as heap-size
// the length will be element + 1
// index starting from 1

void printArray(int array[], int length)
{
	for (int i = 0; i < length ; i++)
	{
		cout << array[i] << ' ';
	}
	cout << endl;
}

void swapElement(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
	cout << "Swapping " << *a << " and " << *b << endl;
}

void maxHeapify(int heap[], int index)
{
	if (index < heap[0])
	{
		int largest = 0;
		int left = index << 1;
		int right = (index << 1) + 1;
		if (left < heap[0] + 1 && heap[left] > heap[index]) // heap[0]+1 -> <=
		{
			largest = left;
		}
		else
		{
			largest = index;
		}

		if (right < heap[0] + 1 && heap[right] > heap[largest]) // heap[0]+1 -> <=
		{
			largest = right;
		}

		if (largest != index)
		{
			swapElement(&heap[index], &heap[largest]);
			maxHeapify(heap, largest);
		}
	}
}

void buildMaxHeap(int heap[])
{
	int length = sizeof(heap) / sizeof(heap[0]);
	for (int i = length / 2; i > -1; i--)
	{
		maxHeapify(heap, i);
	}
}

void heapSort(int heap[])
{
	int length = sizeof(heap) / sizeof(heap[0]);
	for (int i = length; i > 0; i--)
	{
		swapElement(&heap[0], &heap[i]);
	}
}

int heapMaximum(int heap[])
{
	return heap[0];
}

int main(void)
{
	int heap[10] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
	buildMaxHeap(heap);
	printArray(heap, 10);
}
