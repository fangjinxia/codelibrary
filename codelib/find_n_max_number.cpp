/*不到最后无法求出最大数据的算法，（插入算法，合并算法，基数排序）
 * 这些算法的特点就是可以保证局部的数据基本有序，但是无法保证全局的数据有序。
 * 在全部数据得到正确地排序之前，没有人知道最大的数据是什么。
 * 所以针对这个题目而言，要想知道最大的n个数，那就等于要对所有的数据全部排序一遍。
 */


/*
 *每次求出一个最大的数据，依次类推，直到所有的数据都已经排序。
 *（冒泡排序、希尔排序、选择排序、堆排序）
 *
 *以冒泡排序为例
 */
void find_n_max_number(int array[], int length, int number)
{
    int inner ;
    int outer;
    int median;
 
    if(NULL == array || 0 == length)
        return;
 
    if(number > length)
        return;
 
    for(outer = length -1; outer > (length - 1 - number); outer --){
        for(inner = 0; inner < outer; inner ++){
            if(array[inner] > array[inner +1]){
                median = array[inner];
                array[inner]  = array[inner + 1];
                array[inner + 1]= median;
            }
        }
    }
}


/*
 *迭代搜索，首先对数据进行分类，小于于数组第一个数据的排在左边，大于的排在右边。
 *如果右边的数据小于n，为m，那么在左边数组继续寻找剩下的（n-m）个数据；
 *如果右边的数据大于n，那么在右边的数据继续寻找。（快速排序）
 */
int partion(int array[], int start, int end, int swap[])
{
	int loop;
	int left = 0;
	int right = end - start;
	int value = array[start];

	for(loop = start +1; loop <= end; loop++){
		if(array[loop] < value)
			swap[left ++] = array[loop];
		else
			swap[right --] = array[loop];
	}
	swap[left] = value;
	memmove(&array[start], swap, sizeof(int) * (end - start +1));
	return left + start;
}

void _quick_sort(int array[], int start, int end, int swap[], int number)
{
	int middle;

	if(start < end){
		middle = partion(array, start, end, swap);

		if((number - 1) > (end - middle))
		    _quick_sort(swap, start, middle -1, swap, number - (end - middle + 1));
		else
		    _quick_sort(swap, middle + 1, end, swap, number);
	}
}

void find_n_max_number(int array[], int length, int number)
{
	int* swap ;
	if(NULL == array || 0 == length)
		return;

	swap = (int*)malloc(sizeof(int) * length);
	_quick_sort(array, 0, length-1, swap, number);
	free(swap);
}


 

