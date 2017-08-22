/*
 *通过比较来找到合适的位置插入元素已达到排序目的。插入一个数时要保证前面的数已经是有序的，时间复杂度为O(n^2)
 *
 */
void insertSort(vector<int>& arr){
    if(arr.size() == 0)
        return;
    int n = arr.size();
    for(int i = 1; i < n; i++){//i从1开始，假设第一个数的位置正确
        int target = arr[i];//arr[i]是待插入的数
        int j = i;
        for(; j > 0; j--){
            if(arr[j-1] > target)
                arr[j] = arr[j-1];
            else
                break;
        }
        arr[j] = target;
    }

    //打印排序后数组
    for(int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;


}

int main(){
    int myints[] = {9,3,6,3,2,8};
    vector<int> arr(myints, myints+sizeof(myints)/sizeof(int));
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
    cout << endl;
    insertSort(arr);
}
