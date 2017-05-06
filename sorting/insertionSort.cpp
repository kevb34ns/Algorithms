void insertionSort(int* array, int begin, int end)
{
   for (int i = begin + 1; i < end; i++)
   {
      for (int j = begin; j < i; j++)
      {
         if (array[i] <= array[j])
         {
            int temp = array[i];
            for (int k = i; k > j; k--)
            {
               array[k] = array[k - 1];
            }
            array[j] = temp;
            break;
         }
      }
   }
}
