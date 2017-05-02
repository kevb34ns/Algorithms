void sort(int* array, int size)
{
   for (int i = size - 1; i > 0; i--)
   {
      int maxPos = 0;

      for (int j = 1; j <= i; j++)
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
