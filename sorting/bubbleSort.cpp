void bubbleSort(int* array, int begin, int end)
{
   for (int i = end - 1; i > begin; i--)
   {
      bool sorted = true;
      
      for (int j = begin; j < i; j++)
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
