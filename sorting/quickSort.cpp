#include "insertionSort.cpp"

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int findPivotIndex(int* array, int begin, int end)
{
	int mid = begin + (end - begin) / 2;
	if (array[mid] < array[begin])
	{
		swap(array[begin], array[mid]);
	}

	if (array[end - 1] < array[begin])
	{
		swap(array[begin], array[end - 1]);		
	}
	else if (array[end - 1] < array[mid])
	{
		swap(array[mid], array[end - 1]);
	}

	return mid;
}

int partition(int* array, int begin, int end, int pivotIndex)
{
	// swap pivot to the end to get it out of the way
	swap(array[pivotIndex], array[end - 1]);
	pivotIndex = end - 1;
	int fromLeft = begin, fromRight = pivotIndex - 1;
	
}

void quickSort(int* array, int begin, int end)
{
	// find pivot
	// partition about pivot
	// call quicksort on each section
	if (end - begin < 4)
	{
		//TODO insertionSort, what about end-begin is 0 or neg
		return;
	}

	int pivotIndex = findPivotIndex(array, begin, end);

	pivotIndex = partition(array, begin, end, pivotIndex);

	quickSort(array, begin, pivotIndex);
	quickSort(array, pivotIndex + 1, end);
}