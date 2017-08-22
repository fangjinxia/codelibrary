/*
 *利用递归，把问题划分成两个子问题，然后合并结果
 *
 */
void merge(vector<int>& arr, int lo, int mid, int hi){
    vector<int> v(hi-lo+1);
    int i = lo;
    int j = mid+1;
    int k = 0;
    while(i <= mid && j <= hi){
        if(arr[i] < arr[j])
            v[k++] = arr[i++];
        else
            v[k++] = arr[j++];
    }
    while(i <= mid)
        v[k++] = arr[i++];
    while(j <= hi)
        v[k++] = arr[j++];

    for(i = 0; i < v.size(); i++)
        arr[lo+i] = v[i];
}

void mergeSort(vector<int>& arr, int lo, int hi){
    if(lo >= hi)
        return;
    int mid = lo + (hi-lo)/2;
    mergeSort(arr, lo, mid);//递归进行左边排序
    mergeSort(arr, mid+1, hi);//递归进行右边排序
    merge(arr, lo, mid, hi);
}

int main(){
    int myints[] = {9,3,6,3,2,8};
    vector<int> arr(myints, myints+sizeof(myints)/sizeof(int));
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
    cout << endl;

    mergeSort(arr, 0, arr.size()-1);

    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
    cout << endl;
}