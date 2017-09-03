///<from : http://blog.csdn.net/morewindows/article/details/7354571
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
  
    printf("逆序前:    ");  
    unsigned short a = 34520;  
    PrintfBinary(a);  
  
    printf("逆序后:    ");   
    a = ((a & 0xAAAA) >> 1) | ((a & 0x5555) << 1);  
    a = ((a & 0xCCCC) >> 2) | ((a & 0x3333) << 2);  
    a = ((a & 0xF0F0) >> 4) | ((a & 0x0F0F) << 4);  
    a = ((a & 0xFF00) >> 8) | ((a & 0x00FF) << 8);  
    PrintfBinary(a);  
}  