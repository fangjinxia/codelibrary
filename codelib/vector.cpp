/*
 * vector基本操作
 *
 */
 vector<int> arr;
 
 
///<返回elem的最后一个可安插位置，也就是“元素值>elem”的第一个元素位置
vector<int>::iterator it = upper_bound(arr.begin(), arr.end(), elem);

///<计算第一个大于elem元素的下标
int idx = it - arr.begin();

///<复制arr中，下标lo到hi的所有元素，赋值给res
vector<int> res;
res.assign(arr.begin()+lo, arr.begin()+hi+1);///<注意加1

///<复制区间[beg, end]内元素，赋值给v
arr.assign(beg, end) //复制区间[beg, end]内元素，赋值给arr



