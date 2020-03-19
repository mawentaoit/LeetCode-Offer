/**
 * 问题1：判断一个数组是否含重复元素
 * 方法1：可以用map统计每个元素出现的次数
 * 时间复杂度O(n)
 * 空间复杂度O(n)
 * 方法2：sort后判断，不需要额外空间时间复杂度为O(nlogn);
 */
//方法1：set
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return false;
        unordered_set<int> mp;
        for(int i = 0; i < len; i++) {
            if(mp.find(nums[i]) == mp.end()) mp.insert(nums[i]);
            else return true;
        }
        return false;
    }
};
//方法2：sort
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return false;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < len; i++) {
            if(nums[i] == nums[i-1]) return true;
        }
        return false;
    }
};

/**
 * 287 问题：查找数组中的重复数字(长度为n+1,所有数字在1-n范围内，找出数组中任意一个重复数字，不能修改数组)
 * 方法1：sort
 */
//方法1；sort O(nlogn), O(1)
class Solution{
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.empty()) return -1; //表示没有重复数字
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == nums[i-1]) return nums[i];
        }
        return -1;
    }
};
//方法2：哈希表
class Solution
{
public:
   int findDuplicate(vector<int>& nums)
    {
        int len = nums.size();
        if(len < 2) return false;
        unordered_set<int> mp;
        for(int i = 0; i < len; i++) {
            if(mp.find(nums[i]) == mp.end()) mp.insert(nums[i]);
            else return nums[i];
        }
        return false;
    }
};
//方法3：下标比较交换法O(n),O(1)会改变数组
bool duplicate(int a[], int length, int* duplication) {
    //1.数组异常
    if(a == nullptr || length < 0) return false;
    //2.数组值不符合条件时的处理
    for(int i = 0; i < length; i++) {
        if(a[i] < 0 || a[i] > length - 1) return false;
    }
    //比较a[i]与i,如果相等，i++
    //如果不相等，比较a[i] 与a[a[i]],若相等为重复，若不相等交换
    for(int i = 0; i < length; i++) {
        while(a[i] != i) {
            if(a[i] == a[a[i]]) {
                *duplication = a[i];
                return true; //这里也可以返回重复的数字
            }else swap(a[i], a[a[i]]); //
        }
    }
    return false;
}
//方法3：快慢指针 O(n),O(1)且不用改变数组
/**
 * 将索引看做当前结点地址，将存储数看作指向下一个节点的指针，则重复数字即为入环入口
 * 把第一个结点当做头结点
例子：
1 4 3 5 2 2
索引分别为0、1、2、3、4、5
0    1    4    2    3    5
1 -> 4 -> 2 -> 3 -> 5 -> 2
               ↑←-------←↓
注：
    (1)如果在多一个重复数字2，则会多一个结点指向2，但是该结点永远无法被访问到，因为没有结点指向它
    (2)如果数组中不存在重复数字，则为循环链表，相当于循环链表，这个时候需返回-1.
    (3)如果多个数字重复，只有最前面的重复数字构成环，其他重复数字不会在链表中，所以只能检测一个重复数字
    (4)如果数组中有数字0,则该结点会指向头结点，从而形成循环链表，而其他结点会被丢失（所以题目限定不包含0，如果要包含0或负数的话，可以把整个数组预处理一遍，为负数时说明输入非法，为0时，可以将各数加1）
 */
class Solution{
public:
    int findDuplicate(vector<int>& nums) {
        if(num.empty()) return -1;
        int slow = nums[0];
        int fast = nums[num[0]];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        int entry = 0;
        if(entry == slow) return -1; //如果不存在重复
        while(entry != slow) {
            entry = nums[entry];
            slow = nums[slow];
        }
        return entry;
    }
};
