//source: https://tproger.ru/translations/cpp-algorithms

#include <iostream>
#include <algorithm>

using namespace std;

struct Item {
   int value, weight;
   Item(int value, int weight) : value(value), weight(weight) { }
};

bool cmp(struct Item a, struct Item b) {
   double r1 = (double) a.value / a.weight;
   double r2 = (double) b.value / b.weight;
   return r1 > r2;
}

double fractional_knapsack(int W, struct Item arr[], int n)
{
   sort(arr, arr + n, cmp);
   int cur_weight = 0; double tot_value = 0.0;
   for (int i = 0; i < n; ++i)
   {
       if (cur_weight + arr[i].weight <= W)
       {
           cur_weight += arr[i].weight;
           tot_value += arr[i].value;
       }  
       else
       {   // Добавляем часть следующего предмета
           int rem_weight = W - cur_weight;
           tot_value += arr[i].value *
                       ((double) rem_weight / arr[i].weight);                    
           break;
       }
   }
   return tot_value;
}
int main()
{
   int W = 50; // вместительность рюкзака
   Item arr[] = {{60, 10}, {100, 20}, {120, 30}}; // {стоимость, вес}
   int n = sizeof(arr) / sizeof(arr[0]);
   cout << "жадный дробный рюкзак" << endl;
   cout << "максимальная ценность: " << fractional_knapsack(W, arr, n);
   cout << endl;
   return 0;
}
