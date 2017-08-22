/*
 *该排序算法的思想主要来源于冒泡排序，通过比较和交换大数小数来实现，
 *在把小数放在前面的同时也把大数放到了后面，该算法还运用了二分法和递归分治的思想，
 *但不稳定，其平均时间复杂度为O(nlogn)
 *
 */
void swap(vector<int>& arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(vector<int>& arr, int lo, int hi){
    int pK = arr[lo];
    int p = lo;
    while(lo < hi){
        //因为lo和hi相遇时，需要交换基准数和相遇的位置，一般选择第一个数为基准数，
        //所以交换位置上的数应该比基准数小，所以hi先移动.
        while(lo < hi && arr[hi] >= pK){
            hi--;
        }
        while(lo < hi && arr[lo] <= pK){
            lo++;
        }
        swap(arr, lo, hi);
    }
    swap(arr, lo, p);//交换基准值和相遇的位置
    return lo;
}

void quickSort(vector<int>& arr, int lo, int hi){
    if(lo >= hi)
        return;
    int pos = partition(arr, lo, hi);
    quickSort(arr, lo, pos-1);
    quickSort(arr, pos+1, hi);
}

int main(){
    int myints[] = {9,3,6,3,2,8};
    vector<int> arr(myints, myints+sizeof(myints)/sizeof(int));
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
    cout << endl;
    quickSort(arr, 0, arr.size()-1);
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
    cout << endl;
}