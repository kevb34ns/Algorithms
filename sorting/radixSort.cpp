#include <string>
#include <cstdlib>
#include <list>

std::string pad(const std::string& digitString, const unsigned int length)
{
   std::string result = "";
   if (length <= digitString.length())
   {
      result += digitString;
      return result;
   }

   for (unsigned int i = 0; i < length - digitString.length(); i++)
   {
      result += "0";
   }

   result += digitString;
   return result;
}

int toDigitArray(int* array, std::list<std::string>* digitList1, int size)
{
   unsigned int maxLength = 0;
   std::list<std::string> tempList;
   for (int i = 0; i < size; i++)
   {
      tempList.push_back(std::to_string(array[i]));
      if (tempList.rbegin()->length() > maxLength)
      {
         maxLength = tempList.rbegin()->length();
      }
   }

   std::list<std::string>::iterator iter;
   for (iter = tempList.begin(); iter != tempList.end(); iter++)
   {
      digitList1->push_back(pad(*iter, maxLength));
   }

   return maxLength;
}

void toIntArray(int* array, std::list<std::string>* digitList1)
{
   std::list<std::string>::iterator iter;
   int i = 0;
   for (iter = digitList1->begin(); iter != digitList1->end(); iter++)
   {
      array[i] = std::stoi(*iter, nullptr);
      i++;
   }
}

void radixSort(int* array, int begin, int end)
{
   int size = end - begin;
   std::list<std::string>* digitList1 = new std::list<std::string>();
   int digitLength = toDigitArray(array, digitList1, size);
   
   std::list<std::string>* digitList2 = new std::list<std::string>();
   for (int k = 0; k < digitLength; k++)
   {
      for (int j = 0; j < 10; j++)
      {
         std::list<std::string>::iterator iter = digitList1->begin();
         while (iter != digitList1->end())
         {
            if ((*iter)[digitLength - k - 1] == j + '0')
            {
               digitList2->push_back(*iter);
               iter = digitList1->erase(iter);
            }
            else
            {
               ++iter;
            }
         }
      }

      std::list<std::string>* tempList = digitList1;
      digitList1 = digitList2;
      digitList2 = tempList;
   }

   toIntArray(array, digitList1);
   delete digitList1;
   delete digitList2;
}
