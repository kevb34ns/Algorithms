void merge(int* array, int begin, int mid, int end)
{
   int i = begin, j = mid;
   int* tempArray = new int[end - begin];
   for (int k = 0; k < end - begin; k++)
   {
      if (i < mid && (j >= end || array[i] < array[j]))
      {
         tempArray[k] = array[i];
         i++;
      }
      else
      {
         tempArray[k] = array[j];
         j++; 
      }
   }


   for (int i = begin; i < end; i++)
   {
      array[i] = tempArray[i - begin];
   }

   delete[] tempArray;
}

/**
 * A mergesort implementation.
 * @param array The array of integers to sort. 
 * @param begin The first index of the section of the array to sort, inclusive.
 * @param end   The last index of the section to sort, exclusive.
 */
void mergeSort(int* array, int begin, int end)
{
   if (end - begin <= 1)
   {
      return;
   }

   int mid = begin + (end - begin) / 2;

   mergeSort(array, begin, mid);
   mergeSort(array, mid, end);

   merge(array, begin, mid, end);
}