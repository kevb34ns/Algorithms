void bubbleSort(int* array, int size)
{
   for (int i = size - 1; i > 0; i--)
   {
      bool sorted = true;
      
      for (int j = 0; j < i; j++)
      {
         if (array[j] > array[j + 1])
         {
            int temp = array[j + 1];
            array[j + 1] = array[j];
            array[j] = temp;
            sorted = false;
         }
      }

      if (sorted)
      {
         return;
      }
   }
}
