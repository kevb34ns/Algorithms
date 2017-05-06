#include <ctime>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "selectionSort.cpp"
#include "bubbleSort.cpp"
#include "insertionSort.cpp"
#include "mergeSort.cpp"
#include "quickSort.cpp"

enum SortType
{
   selection,
   bubble,
   insertion,
   merger,
   quick
};

void print(int* array, int size)
{
   for (int i = 0; i < size; i++)
   {
      std::cout << array[i];
      if (i == size - 1)
      {
         std::cout << std::endl;
      }
      else
      {
         std::cout << ", ";
      }
   }
}

int main(int argc, char** argv)
{
   int N = 100;
   int LIMIT = 1000;
   bool isPrintEnabled = false;
   SortType type = merger;

   const char* helpString = "USAGE: bin/sortTest [OPTIONS]\n \
      OPTIONS:\n \
      -n <inputSize>: specify number of ints to sort\n \
      -s : use selection sort\n \
      -b : use bubble sort\n \
      -i : use insertion sort\n \
      -m : use merge sort\n \
      -q : use quick sort\n \
      -p : print sorted list\n \
      -h : show usage";

   for (int i = 1; i < argc; i++)
   {
      if (argv[i][0] == '-' && strlen(argv[i]) == 2)
      {
         switch (argv[i][1])
         {
            case 'n':
               N = atoi(argv[i + 1]);
               break;
            case 's':
               type = selection;
               break;
            case 'b':
               type = bubble;
               break;
            case 'i':
               type = insertion;
               break;
            case 'm':
               type = merger;
               break;
            case 'q':
               type = quick;
               break;
            case 'p':
               isPrintEnabled = true;
               break;
            case 'h':
            default:
               std::cerr << helpString << std::endl;
               return 0;
         }
      }
   }

   int* array = new int[N];

   srand(time(nullptr));
   for (int i = 0; i < N; i++)
   {
      array[i] = rand() % LIMIT + 1;
   }

   clock_t startTime = clock();

   switch (type)
   {
      case selection: selectionSort(array, 0, N); break;
      case bubble: bubbleSort(array, 0, N); break;
      case insertion: insertionSort(array, 0, N); break;
      case merger: mergeSort(array, 0, N); break;
      case quick: quickSort(array, 0, N); break;
      default: delete[] array; return -1;
   }

   double ticks = clock() - startTime;
   double duration = ticks / (double) CLOCKS_PER_SEC;

   bool sorted = true;
   for(int i = 0; i < N - 1; i++)
   {
      if (array[i] > array[i + 1])
      {
         std::cout << "Sort error at index" << i << 
               ": " << array[i] << " > " << array[i + 1] 
               << std::endl;
         sorted = false;
      }
   }

   if (isPrintEnabled)
   {
      print(array, N);
   }

   if (sorted)
   {
      std::cout << "RESULT: List is sorted correctly." << std::endl;
   }
   else
   {
      std::cout << "RESULT: List is sorted incorrectly." << std::endl;
   }

   std::cout << "Time: " << duration << " seconds." << std::endl;

   delete[] array;

   return 0;
}
