#include <cmath>

int findMax(const int* array, const int size)
{
   int max = array[0];
   for (int i = 1; i < size; i++)
   {
      if (array[i] > array[max])
      {
         max = array[i];
      }
   }

   return max;
}

unsigned int getNumDigits(const int num)
{
   int exp = 1;
   int i = 1;
   while (true)
   {
      if ((num / exp) % 10 == 0)
      {
         return i;
      }

      exp *= 10;
      i++;
   }
}

void swapInts(int& x, int& y)
{
   int temp = x;
   x = y;
   y = temp;
}

void radixSort(int* array, const int begin, const int end)
{
   const int size = end - begin;
   const int numDigits = getNumDigits(findMax(array, size));

   // radix sort divides the array into contiguous groups based on digit values
   // groupIndices stores the ending index, exclusive, of each group
   // for example, groupIndices[3] = 15 means that the last item in group 3 is
   // at index 14
   int groupIndices[10];
   for (int i = 1; i <= numDigits; i++)
   {
      int exp = std::pow(10, i - 1);

      for (int j = 0; j < 10; j++)
      {
         int openIndex = (j > 0) ? groupIndices[j - 1] : 0;
         for (int k = 0; k < size; k++)
         {
            if ((array[k] / exp) % 10 == j)
            {
               // ERROR by swapping here you break the rule that the order is preserved within each group
               // TODO need a second array of the same size that you place the groups in, then switch between each array, and in the end, make sure 'array' has the final sorted values
               swapInts(array[k], array[openIndex]);
               openIndex++;
            } 
         }
         groupIndices[j] = openIndex;
      }
   }
}
