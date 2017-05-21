void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

/**
 * Finds the pivot by sorting the first, middle, and last items in the
 * array, and returning the median of the three items as the pivot.
 */
int findPivotIndex(int* array, int begin, int end)
{
	int mid = begin + (end - begin) / 2;
	if (array[mid] < array[begin])
	{
		swap(array[begin], array[mid]);
	}

	if (array[end - 1] < array[begin])
	{
		int temp = array[end - 1];
		array[end - 1] = array[mid];
		array[mid] = array[begin];
		array[begin] = temp;		
	}
	else if (array[end - 1] < array[mid])
	{
		swap(array[mid], array[end - 1]);
	}

	return mid;
}

/**
 * Partitions the array around the pivot. This function is only made to work
 * with pivots chosen using the median-of-three method described above, and
 * must be re-written if using a different method.
 */
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
	int pivotIndex = -1;
	if (segmentSize >= 3)
	{
		pivotIndex = findPivotIndex(array, begin, end);
	}

	if (segmentSize < 4)
	{
		if (segmentSize == 2 && array[begin] > array[begin + 1])
		{
			swap(array[begin], array[begin + 1]);
		}
		return;
	}

	pivotIndex = partition(array, begin, end, pivotIndex);

	quickSort(array, begin, pivotIndex);
	quickSort(array, pivotIndex + 1, end);
}