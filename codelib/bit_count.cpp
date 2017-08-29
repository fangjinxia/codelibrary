#include<iostream>

using namespace std;
///<计算一个字中1的个数(MIT牛人算法)
int bitcount(unsigned int n)
{
    unsigned int tmp;

    tmp = n - ((n >> 1) & 033333333333)
            - ((n >> 2) & 011111111111);
    return ((tmp + (tmp >> 3)) & 030707070707)%63;
}


int main(int argc,char*argv[])
{
    int n;
    cin >> n;
    cout  << bitcount(n) << endl;
    return 0;
}