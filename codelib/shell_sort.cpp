/*
 *希尔排序也叫缩小增量排序，基本思想是先将整个待排记录序列分割成为若干子序列分别进行直接插入排序，待整个序列中的记录基本有序时再对全体记录进行一次直接插入排序。 
 *因此希尔排序的特点是，子序列的构成不是简单的逐段分割，而是将某个相隔某个增量的记录组成一个子序列。
 *
 */
#include<iostream>
#include<cstring>
#include<vector>

using namespace std;
///<
void shellInsert(vector<int>& nums, int k){
    for(int i = k; i < nums.size(); i++){
        int j = i - k;
        int temp = nums[i];
        ///<从后往前，找比nums[i]小的数，若比其大，这往后移
        while(j >= 0 && nums[j] > temp){
            nums[j+k] = nums[j];
            j -= k;
        }
        if(j != i-k)///<存在比其小的数
            nums[j+k] = temp;
    }
}

///<希尔排序
void shellSort(vector<int>& nums){
    if(nums.size() == 0)
        return;

    int k = nums.size()/2;
    while(k > 0){
        shellInsert(nums, k);
        k /= 2;
    }
}

int main()
{
    int myints[] = {9,3,6,3,2,8};
    vector<int> arr(myints, myints+sizeof(myints)/sizeof(int));
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
    cout << endl;

    shellSort(arr);
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
    cout << endl;

}