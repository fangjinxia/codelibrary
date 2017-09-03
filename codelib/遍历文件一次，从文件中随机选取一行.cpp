//只遍历文件一次，从文件中取机选取一行  
/*
 *举个例子，假设文件有3行
 *选中第一行的概率为1 * 1/2 * 2/3 = 1/3。
 *选中第二行的概率为1/2 * 2/3 = 1/3。
 *选中第三行的概率为1/3。
 */

故每一行被选中是等概率的。
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  
int main()  
{  
    int i, num, nChooseNum;  
    const char strFileName[] = "in.txt";  
      
    freopen(strFileName, "r", stdin);  
    srand(time(NULL));  
    i = 1;  
    while (scanf("%d", &num) != EOF)  
    {  
        if (rand() % i == 0)  
            nChooseNum = num;  
        i++;  
    }  
    printf("从文件中选取出: %d\n", nChooseNum);  
    return 0;  
}  