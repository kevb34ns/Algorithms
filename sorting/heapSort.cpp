/**
 * Heap Sort algorithm, using several methods copied from
 * my own Heap implementation, which can be found at:
 * https://github.com/kevinkyang/DataStructures
 */

void swap(int* array, int size, int index1, int index2)
{
    if (index1 < 0 || index1 >= size || index2 < 0 || index2 >= size)
    {
        return;
    }

    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

bool isLeaf(int* array, int size, int index)
{
    if (index < 0 || index >= size)
    {
        return false;
    }
    else
    {
        return index >= (size + 1) / 2;
    }
}

int getLeftChildIndex(int* array, int size, int parentIndex)
{
    if (parentIndex < 0)
    {
        return -1;
    }

    int leftChildIndex = parentIndex * 2 + 1;
    return (leftChildIndex < size) ? leftChildIndex : -1;
}

int getRightChildIndex(int* array, int size, int parentIndex)
{
    if (parentIndex < 0)
    {
        return -1;
    }

    int rightChildIndex = parentIndex * 2 + 2;
    return (rightChildIndex < size) ? rightChildIndex : -1;
}

void heapRebuild(int* array, int size, int subtreeIndex)
{
    if (subtreeIndex < 0 || subtreeIndex >= size)
    {
        return;
    }

    int left = getLeftChildIndex(array, size, subtreeIndex);
    int right = getRightChildIndex(array, size, subtreeIndex);
    
    if (isLeaf(array, size, subtreeIndex) || (array[subtreeIndex] >= array[left] && 
                                 array[subtreeIndex] >= array[right]))
    {
        return;
    }

    if (array[left] >= array[right])
    {
        swap(array, size, subtreeIndex, left);
        heapRebuild(array, size, left);
    }
    else
    {
        swap(array, size, subtreeIndex, right);
        heapRebuild(array, size, right);
    }
}

void heapify(int* array, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapRebuild(array, size, i);
    }
}

void heapSort(int* array, int begin, int end)
{
    int size = end - begin;
    if (size <= 1)
    {
        return;
    }
    // heap region goes from index 0 to index heapSize - 1
    // sorted region goes from index heapSize to size - 1
    int heapSize = size;
    const int ROOT_INDEX = 0;

    heapify(array, size);

    do
    {
        swap (array, heapSize, ROOT_INDEX, heapSize - 1);
        heapSize--;
        heapRebuild(array, heapSize, ROOT_INDEX);

    } while (heapSize > 1);
}
