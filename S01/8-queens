//source: https://tproger.ru/translations/cpp-algorithms

#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

// row[8]: номер строки для каждого ферзя
// TC: счётчик TraceBack
// (a, b): расположение первого ферзя от (r=a, c=b)
int row[8], TC, a, b, line_counter;

bool place(int r, int c)
{  
   // Проверяем ранее размещённых ферзей
   for (int prev = 0; prev < c; prev++)
   {
       // Проверяем, совпадают ли строки или диагонали
       if (row[prev] == r || (abs(row[prev] - r) == abs(prev - c)))
           return false;
   }
   return true;
}

void backtrack(int c)
{
   // Возможное решение; первый ферзь имеет координаты a и b
   if (c == 8 && row[b] == a)
   {
       printf("%2d %d", ++line_counter, row[0] + 1);
       for (int j = 1; j < 8; j++) printf(" %d", row[j] + 1);
       printf("\n");
   }
   // Пробуем все возможные строки
   for (int r = 0; r < 8; r++)
   {
       if (place(r, c))
       {
           row[c] = r; // место ферзя в этом столбце и в этой строке
           backtrack(c + 1); // следующий столбец и рекурсия
       }
   }
}

int main()
{
    scanf("%d", &TC);
    while (TC--)
    {
       scanf("%d %d", &a, &b);
       a--; b--; // индексируем с нуля

       memset(row, 0, sizeof(row));
       line_counter = 0;
       printf("РЕШ\tСТОЛБЕЦ\n");
       printf(" # 1 2 3 4 5 6 7 8\n\n");
       backtrack(0); // генерируем все 8! возможных решений
       if (TC) printf("\n");
    }
    return 0;
}
