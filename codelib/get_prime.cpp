//from : http://blog.csdn.net/morewindows/article/details/7354571
//使用位操作压缩后的筛素数方法    
#include <stdio.h>  
#include <memory.h>  
const int MAXN = 100;  
int flag[MAXN / 32 + 1];  
int primes[MAXN / 3 + 1], pi;  
void GetPrime_1()  
{  
    int i, j;  
    pi = 0;  
    memset(flag, 0, sizeof(flag));  
    for (i = 2; i < MAXN; i++)  
        if (!((flag[i / 32] >> (i % 32)) & 1))  
        {  
            primes[pi++] = i;  
            for (j = i; j < MAXN; j += i)  
                flag[j / 32] |= (1 << (j % 32));  
        }  
}  
void PrintfArray()  
{  
    for (int i = 0; i < pi; i++)  
        printf("%d ", primes[i]);  
    putchar('\n');  
}  
int main()  
{   GetPrime_1();  
    PrintfArray();  
    return 0;  
}  