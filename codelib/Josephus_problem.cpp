/*
 *来自https://baike.baidu.com/item/%E7%BA%A6%E7%91%9F%E5%A4%AB%E9%97%AE%E9%A2%98#2_6
*/

#include <iostream>

using namespace std;

int main()
{
    bool a[101]={0};
    int n,m,i,f=0,t=0,s=0;
    cin>>n>>m;///<N个人围成一圈，从第一个开始报数，第M个将被杀掉，最后剩下一个，其余人都将被杀掉。
    do
    {
        ++t;//逐个枚举圈中的所有位置
        if(t>n)
            t=1;//数组模拟环状，最后一个与第一个相连
        if(!a[t])
            s++;//第t个位置上有人则报数
        if(s==m)//当前报的数是m
        {
            s=0;//计数器清零
            cout<<t<<' ';//输出被杀人编号
            a[t]=1;//此处人已死，设置为空
            f++;//死亡人数+1
        }
    }while(f!=n);//直到所有人都被杀死为止

    return 0;
}

