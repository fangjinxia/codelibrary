/*
 * 计算x的n次幂，最简单的方法就是相乘n次，效率不高
 * 方法二是利用二分法，计算N次幂只要相乘O(logN)次，需要用到递归
 * 递归会有很多重复计算，
 * 方法三利用二进制的位操作，如求2^23，23的二进制为10111，因此2^23 = 2^16 * 2^4 * 2^2 * 2^1 
 * 方法四可以在方法三的基础上，作进一步的优化
 * 如48的二进制为110000，可以过滤掉低位的0，再计算，效率会高些
 */

 
 ///<方法二：
int power2(int x, unsigned int n)  
{  
    if (n == 0)  
        return 1;  
    else if (n == 1)  
        return x;  
    else   
    {  
        if (n % 2 == 1)  
            return power2(x, n / 2) * power2(x, n / 2) * x;  
        else  
            return power2(x, n / 2) * power2(x, n / 2);  
    }  
}  


///<方法三：
int power(int x, unsigned int n)  
{  
    if (n == 0)  
        return 1;  
	
    int result = 1;  
    while (n != 0)  
    {  
        if ((n & 1) != 0)  
            result *= x;  
        x *= x;  
        n >>= 1;  
    }  
    return result;  
}  

///<方法四：
int power4(int x, unsigned int n)  
{  
    if (n == 0)  
    {  
        return 1;  
    }  
    else  
    {  
        while ((n & 1) == 0)  
        {  
            n >>= 1;  
            x *= x;  
        }  
    }  
    int result = x;  
    n >>= 1;  
    while (n != 0)  
    {     
        x *= x;  
        if ((n & 1) != 0)  
            result *= x;  
        n >>= 1;  
    }  
    return result;  
}  