/*
 * 举个例子，序列为[1, 2, 3]，有6种可能的排列
 * 1.先调整前二个元素即[1, 2，3]先生成[1，2，3]或[2，1，3]
 * 2.对于[1,2,3],第三个元素以1/3的概率与第一，第二，第三个元素进行交换就可以等概率的得到[3，2，1]、[1，3，2]和[1，2，3]
 * 同理，对于[2,1,3],得到排列[3，1，2]、[2，3，1]和[2，1，3]
 */
 
//随机重新排列  
//参照STL中的random_shuffle  
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  
inline void Swap(int *a, int *b)  
{  
    int c = *a;  
    *a = *b;  
    *b = c;  
}  
//随机重新排列函数  
void Random_shuffle(int a[], int n)  
{  
    srand(time(NULL));  
    for (int i = 1; i < n; i++)  
        Swap(&a[i], &a[rand() % (i + 1)]);  ///<关键点
}  
void PrintfIntArray(int a[], int n)  
{  
    for (int i = 0; i < n; i++)  
        printf("%d ", a[i]);  
    putchar('\n');  
}  
int main()  
{  
    const int MAXN = 8;  
    int a[MAXN] = {1, 2, 3, 4, 5, 6, 7, 8};  
  
    printf("原数组:\n");  
    PrintfIntArray(a, MAXN);  
  
    Random_shuffle(a, MAXN);  
  
    printf("随机重新排列后:\n");  
    PrintfIntArray(a, MAXN);  
    return 0;  
}  