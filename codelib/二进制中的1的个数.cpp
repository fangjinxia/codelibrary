///<from : http://blog.csdn.net/morewindows/article/details/7354571
//二进制中1的个数 
#include <stdio.h>  
template <class T>  
void PrintfBinary(T a)  
{  
    int i;  
    for (i = sizeof(a) * 8 - 1; i >= 0; --i)  
    {  
        if ((a >> i) & 1)  
            putchar('1');  
        else   
            putchar('0');  
        if (i == 8)  
            putchar(' ');  
    }  
    putchar('\n');  
}  
int main()  
{  
    unsigned short a = 34520;  
    printf("原数    %6d的二进制为:  ", a);  
    PrintfBinary(a);  
      
    a = ((a & 0xAAAA) >> 1) + (a & 0x5555);  
    a = ((a & 0xCCCC) >> 2) + (a & 0x3333);  
    a = ((a & 0xF0F0) >> 4) + (a & 0x0F0F);  
    a = ((a & 0xFF00) >> 8) + (a & 0x00FF);     
    printf("计算结果%6d的二进制为:  ", a);     
    PrintfBinary(a);  
    return 0;  
}  