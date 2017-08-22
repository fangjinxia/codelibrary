/*
 *所谓堆排序是利用堆来实现的选择排序，需要注意的是如果想升序排序就借助大顶堆，反之借助小顶堆，因为堆顶元素需要交换到序列的尾部。 
 *堆实际上是一棵完全二叉树，其任何一非叶节点满足性质：

 *Key[i]<=key[2i+1]&&Key[i]<=key[2i+2] 或者 
 *Key[i]>=Key[2i+1]&&key>=key[2i+2]

 *即任何一非叶节点的数值不大于或者不小于其左右孩子节点的数值。 
 *因此满足Key[i]>=Key[2i+1]&&key>=key[2i+2]称为大顶堆，满足 Key[i]<=key[2i+1]&&Key[i]<=key[2i+2]称为小顶堆。由上述性质可知大顶堆的堆顶的数值肯定是所有数值中最大的，小顶堆的堆顶的数值是所有数值中最小的。 
 *主要操作过程如下： 
 *1.初始化堆：将nums[1..n]构造为堆； 
 *2.将当前无序区的堆顶元素nums[1]同该区间的最后一个记录交换，然后将新的无序区调整为新的堆。
 *
 */
#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

///<交换两个元素
void swap(vector<int>& nums, int i, int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

///<调整堆
void heapAdjust(vector<int>& nums, int start, int end){
    int temp = nums[start];

    for(int i = 2*start+1; i <= end; i *= 2){
        ///<选择左右子节点中数值较大的下标
        if(i < end && nums[i] < nums[i+1])
            i++;

        if(temp >= nums[i])
            break;///<已经为大顶堆
        nums[start] = nums[i];///<将子节点上移

        start = i;
    }
    nums[start] = temp;
}

///<堆排序
void heapSort(vector<int>& nums){
    if(nums.size() == 0)
        return;

    ///<建立大顶堆
    for(int i = nums.size()/2; i >= 0; i--){
        heapAdjust(nums, i, nums.size()-1);
    }
    ///<将当前无序区的堆顶元素nums[1]同该区间的最后一个记录交换，
    ///<然后将新的无序区调整为新的堆
    for(int i = nums.size()-1; i >= 0; i--){
        swap(nums, 0, i);
        heapAdjust(nums, 0, i-1);
    }
}

int main()
{
    int myints[] = {9,3,6,3,2,8};
    vector<int> arr(myints, myints+sizeof(myints)/sizeof(int));
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
    cout << endl;

    heapSort(arr);
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
    cout << endl;

}