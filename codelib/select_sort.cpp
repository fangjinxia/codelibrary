/*
 *选择排序是确定了最小的数后进行交换，冒泡排序是通过相邻元素的比较和交换，因此选择排序大大降低了交换的次数，时间复杂度为O(n^2)，
 *
 */
void swap(vector<int>& arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void selectSort(vector<int>& arr){
    if(arr.size() == 0)
        return;
    int n = arr.size();
    for(int i = 0; i < n-1; i++){
        int min = i;
        for(int j = n-1; j > i; j--){
            if(arr[j] < arr[min])
                min = j;
        }
        if(min != i)
            swap(arr, min, i);
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
    selectSort(arr);
}