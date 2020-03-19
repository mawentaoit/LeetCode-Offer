//描述：统计一个数字在排序数组中出现的次数

/**
 * 法1：二分查找
 */
#include <vector>
#include <iostream>
using namespace std;
class Solution{
public:
    int GetNumberOfK(vector<int>& data, int k){
        if(data.empty()) return 0;
        vector<int>::iterator first = lower_bound(data.begin(), data.end(), k); //返回第一个大于等于k的位置
        vector<int>::iterator last = upper_bound(data.begin(), data.end(), k); //返回第一个大于k的位置
        return last - first;
    }
};

//法2：二分查找，找到第一个位置和最后一个位置
class Solution{
public:
    int getNumberOfK(vector<int>& data, int k) {
        if(data.empty()) return 0;
        int first = getFirst(data, k);
        int last = getLast(data, k);
        if(first != -1 && last != -1) return last - first + 1;
        else return 0; //如果找不到就返回0
    }
private:
    int getFist(vector<int>& a, int k) {
        int left = 0;
        int right = a.size() - 1;
        int mid;
        while(left < right) {
            mid = left + (right-left)/2;
            if(a[mid] < k) left = mid+1;
            else if(a[mid] > k) right = mid - 1;
            else if(mid - 1 >= 0 && a[mid-1] == k) right = mid-1;
            else return mid;
        }
        return -1; //找不到返回-1;
    }
    int getLast(vector<int>& a, int k) {
        int left = 0;
        int right = a.size() - 1;
        int mid;
        while(left < right) {
            mid = left + (right - left)/2;
            if(a[mid] < k) left = mid + 1;
            else if(a[mid] > k) right = mid - 1;
            else if(mid - 1 >= 0 && a[mid-1] == k) left = mid+1;
            else return mid;
        }
        return -1;
    }
};