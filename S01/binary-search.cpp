//source: https://tproger.ru/translations/cpp-algorithms

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int bsearch(const vector<int> &arr, int l, int r, int q)
{
   while (l <= r)
   {
       int mid = l + (r-l)/2;
       if (arr[mid] == q) return mid;
      
       if (q < arr[mid]) { r = mid - 1; }
       else              { l = mid + 1; }
   }
   return -1; // не нашли
}

int main()
{
   int query = 10;
   int arr[] = {2, 4, 6, 8, 10, 12};
   int N = sizeof(arr) / sizeof(arr[0]);
   vector<int> v(arr, arr + N);
  
   // Сортируем входной массив
   sort(v.begin(), v.end());
   int idx;
   idx = bsearch(v, 0, v.size(), query);
   if (idx != -1)
       cout << "бинарный поиск: нашли по индексу " << idx;   
   else
       cout << "бинарный поиск: не нашли";
   return 0;
}
