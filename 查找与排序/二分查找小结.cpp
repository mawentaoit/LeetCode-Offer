/**
 * 功能：查找和目标值完全相等的数
 * 返回：如果存在，返回对应位置索引，否则返回-1
 */
int find(vector<int>& a, int target) {
    int left = 0, right = a.size();
    while(left < right) {
        int mid = left + (right-left) / 2;
        if(a[mid] < target) {
            left = mid+1;
        }else if(a[mid] > target) {
            right = mid;
        }else return mid;
        return -1;
    }
}
/***
 * 写法二:
 */
int binarysearch(vector<int>& a, int k) {
    int left = 0;
    int right = a.size() - 1;
    while(left <= right) {
        int mid = left + (right-left) / 2;
        if(a[mid] < k) left = mid+1;
        else if(a[mid] > k) right = mid-1;
        else return mid;
    }
}
/**
 * 类型二：查找第一个大于等于目标的数，可变形为查找最后一个小于目标值的数
 * 完成stl中lower_bound的功能
 * 返回：如果存在，返回对应位置索引，否则返回末尾索引end,数组[begin, end)
 */
int my_lowerbound(vector<int>& a, int target) {
    int left = 0, right = a.size();
    while(left < right) {
        int mid = left + (right-left)/2;
        if(a[mid] < target) 
            left = mid+1;
        else right = mid;
    }
    return right;
}
/**
 * 类型3
 * 功能：查找第一个大于目标值的数，可变形为查找最后一个小于等于目标值的数(返回right-1)
 * 完成stl中upper_bound的功能
 * 返回：如果存在，返回对应位置索引，否则返回末尾索引end,数组[begin, end)
 */
int my_upperbound(vector<int>& a, int target) {
    int left = 0, right = a.size();
    while(left < right) {
        int mid = left + (right-left)/2;
        if(a[mid] <= target) left = mid+1;
        else right = mid;
    }
    return right;
}