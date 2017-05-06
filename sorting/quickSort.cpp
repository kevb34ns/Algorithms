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
	while (true)
	{
		while (array[fromLeft] < array[pivotIndex])
		{
			fromLeft++;
		}

		while (array[fromRight] > array[pivotIndex])
		{
			fromRight--;
		}

		if (fromLeft < fromRight)
		{
			swap(array[fromLeft], array[fromRight]);
			fromLeft++;
			fromRight--;
		}
		else
		{
			break;
		}
	}

	swap(array[fromLeft], array[pivotIndex]);
	pivotIndex = fromLeft;
	return pivotIndex;
}

void quickSort(int* array, int begin, int end)
{
	int segmentSize = end - begin;
	if (segmentSize < 4)
	{
		if (segmentSize > 1)
		{
			insertionSort(array, begin, end);
		}
		return;
	}

	int pivotIndex = findPivotIndex(array, begin, end);

	pivotIndex = partition(array, begin, end, pivotIndex);

	quickSort(array, begin, pivotIndex);
	quickSort(array, pivotIndex + 1, end);
}