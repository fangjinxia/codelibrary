/*
 *"Josephus_pro.h"  
 */

#pragma once 
#include<vector> 
using std::vector;//使用STL中的容器 
class PRO 
{ 
private: 
    int *arr;//动态开辟空间 
    vector<int> vec_int;//用来存储以此被踢出的数字 
    int total_num;//总人数 依据此数据开辟 
    int sig_num;//标志数字 数到次数就被踢出 
    int begin_num;//开始数字 不得大于总人数 
    int index;//下标值 用于存取 
    int remaining_num;//剩余的人数 
    void Running();//计算函数 一个一个踢出的数字 剩余某些 (用0标志已被踢出的标志) 
    void Running_();//删除删除被踢出者 后面的补齐 
public: 
    PRO(int tol_num,int sg_num,int reman_num = 1,int bg_num = 1);//构造函数 初始化必要数据 默认从1开始数起 剩余一个 
    PRO();//无参构造函数 
    ~PRO(); 
    void input();//输入数据 
    void PutResult();//输出结果 
}; 


/*
 *main.cpp
 */
 
#include"Josephus_pro.h"  
#include<iostream>  
using namespace std;  
PRO::PRO(int tol_num,int sg_num,int reman_num ,int bg_num)  
{  
    total_num = tol_num;  
    sig_num = sg_num;  
    begin_num = bg_num;  
    remaining_num = reman_num;  
    arr = new int[total_num];//开辟空间  
    input();//在构造函数执行结束实现输入  
}  
PRO::PRO()//空的构造函数  
{}  
PRO::~PRO()  
{}  
void PRO::Running()  
{  
    int i = 1;//用来数数的 数到标志数就踢  
    index = begin_num - 1;//下标索引被赋值  
    int sum = total_num;//总人数  
    while(sum > remaining_num)  
    {  
       //小循环，寻找被踢的人的索引  
        while(i < sig_num)  
        {  
            index = (index + 1) % total_num; //索引一步一步的往后移动  
            if(arr[index] != 0)  //没有被设置为标志位  
                i++;  
        }  
        vec_int.push_back(arr[index]);  //arr[index]为被踢出的  
        arr[index] = 0;  //置为标志位  
        index = (index + 1) % total_num;  //此时索引要后移一个  
                //后移后会出一个问题，那就是不知道下一个位置是否为标志位，就无法确定i的重新计数值  
        if(arr[index] == 0)  
            i = 0; //如果被设置为标志位  
        else  
            i = 1;  //下一个位置没有被设置为标志位  
  
        sum--;  //一趟大循环会踢出一个  
    }  
}  
  
void PRO::input()  
{  
    cout<<"请输入"<<total_num<<"个数据:"<<endl;  
    for(int i=0;i<total_num;i++)//输入  
        cin>>arr[i];  
}  
void PRO::PutResult()  
{  
    Running();//核心算法被封装  
  
    cout<<"计算结果如下:"<<endl;  
    for(vector<int>::size_type i=0;i<vec_int.size();i++)  
        cout<<"第"<<i+1<<"个被踢出去的数字:"<<vec_int[i]<<endl;  
    cout<<"剩余人:"<<endl;  
    for(int i=0;i<total_num;i++)  
    {  
        if(arr[i] == 0)  
            continue;  
        if(arr[i] != 0)  
            cout<<arr[i]<<endl;//输出剩余的  
    }  
}  
