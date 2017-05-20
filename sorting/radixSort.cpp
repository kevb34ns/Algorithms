#include <cmath>

int findMax(const int* array, const int size)
{
   int max = array[0];
   for (int i = 1; i < size; i++)
   {
      if (array[i] > max)
      {
         max = array[i];
      }
   }

   return max;
}

unsigned int getNumDigits(int num)
{
   num = std::abs(num);
   int numDigits = 0;
   while (num)
   {
      num /= 10;
      numDigits++;
   }
   return numDigits;
}

void transferArrayData(int* from, int* to, int n)
{
   for (int i = 0; i < n; i++)
   {
      to[i] = from[i];
   }
}

void radixSort(int* array, const int begin, const int end)
{
   const int size = end - begin;
   const int numDigits = getNumDigits(findMax(array, size));

   int* swapArray = new int[size];
   for (int i = 1; i <= numDigits; i++)
   {
      int exp = std::pow(10, i - 1);

      int openIndex = 0;
      for (int j = 0; j < 10; j++)
      {
         for (int k = 0; k < size; k++)
         {
            if ((array[k] / exp) % 10 == j)
            {
               swapArray[openIndex] = array[k];
               openIndex++;
            } 
         }
      }

      if (i != numDigits || numDigits % 2 == 0)
      {
         int* tempPtr = swapArray;
         swapArray = array;
         array = tempPtr;
      }
   }

   if (numDigits % 2 != 0)
   {
      transferArrayData(swapArray, array, size);
   }

   delete[] swapArray;
}
