void selectionSort(int* array, int begin, int end)
{
   for (int i = end - 1; i > begin; i--)
   {
      int maxPos = begin;

      for (int j = begin + 1; j <= i; j++)
      {
         if (array[j] > array[maxPos])
         {
            maxPos = j;
         }
      }

      int temp = array[i];
      array[i] = array[maxPos];
      array[maxPos] = temp;
   }
}
