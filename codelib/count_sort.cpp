/*
 *该方法的时间复杂度为O(n)，适用于待排序的数满足一定的范围时，
 *不过计数排序需要比较多的辅助空间。
 *其思想是，用待排序的数作为计数数组的下标，统计每个数字的个数。
 *然后依次输出即可得到有序序列。
 *
 */
//<计数排序
void countSort(vector<int>& nums){
    if(nums.size() == 0)
        return;

    int m = *max_element(nums.begin(), nums.end());///<找到数组中最大的数
    vector<int> v(m+1, 0);///<v中保存着nums数组中每个元素的个数
    for(int i = 0; i < nums.size(); i++){
        v[nums[i]]++;
    }
    int idx = 0;
    for(int i = 0; i <= m; i++){
        for(int j = 0; j < v[i]; j++){
            nums[idx++] = i;
        }
    }
}

int main()
{
    int myints[] = {9,3,6,3,2,8};
    vector<int> arr(myints, myints+sizeof(myints)/sizeof(int));
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
    cout << endl;

    countSort(arr);
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
    cout << endl;

}