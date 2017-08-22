/*
 *每次循环比较把最小的数交换到最前面,循环次数为n-1,时间复杂度为O(n^2)
 *
 */
void swap(vector<int>& arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
//冒泡排序
void bubbleSort(vector<int>& arr){
    if(arr.size() == 0)
        return;
    int n = arr.size();
    for(int i = 0; i < n-1; i++){
        for(int j = n-1; j > i; j--){
            if(arr[j] < arr[j-1])
                swap(arr, j-1, j);
        }
    }

    //打印排序后数组
    for(int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;


}

int main(){
    int myints[] = {9,3,6,2,8};
    vector<int> arr(myints, myints+sizeof(myints)/sizeof(int));
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
    cout << endl;
    bubbleSort(arr);
}