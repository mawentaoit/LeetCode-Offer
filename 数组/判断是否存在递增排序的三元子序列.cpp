/*
给定一个未排序的数组，判断这个数组中是否存在长度为 3 的递增子序列。
如果存在这样的 i, j, k,  且满足 0 ≤ i < j < k ≤ n-1，
使得 arr[i] < arr[j] < arr[k] ，返回 true ; 否则返回 false 。
说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1) 。
输入: [1,2,3,4,5]
输出: true
输入: [5,4,3,2,1]
输出: false
*/
/*
思路首先需要定义两个变量min 和mid保存最小值和中间值，那么一旦出现了比它两个大的那么就返回true
首先遍历一旦遇到比min小的，那么立即用min保存这个值，如果遇到了比min大，比mid小的立即保存，如果比这两个都大就返回true
这里有一个问题就是min的索引可能和mid索引不是严格顺序关系，但是不要紧，如果min索引比mid大，那么一定说明mid前面有一个比mid小的，所以一旦找到
比mid大的数字，那么肯定是存在递增排序的三元子序列的
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) return false;
        int c1 = INT_MAX, c2 = INT_MAX;
        for(int x : nums) {
            if(x < c1) c1 = x;
            else if(x < c2) c2 = x;
            else return true;
        }
        return false;
    }
};