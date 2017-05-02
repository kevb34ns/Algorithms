void sort(int* array, int size)
{
   for (int i = 1; i < size; i++)
   {
      for (int j = 0; j < i; j++)
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
