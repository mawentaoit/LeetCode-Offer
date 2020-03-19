/*
双指针，指针对撞思想
时间复杂度O(n)
空间复杂度O(1)
*/
//找到一个和为s的两个数
#include <climits>
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        if(len < 2) return {};
        int start = 0;
        int end = len - 1;
        while(start < end) {
            if(numbers[start] + numbers[end] > target) end--;
            else if(numbers[start] + numbers[end] < target) start++;
            else {
                return {start+1, end+1};
            }
        }
        return {};
    }
};
//扩展，如果有多对数字的和等于S,那么输出两个数的乘积最小的
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        if(len < 2) return {};
        int min_product = INT_MAX;
        int start = 0;
        int end = len - 1;
        int a1 = 0;
        int a2 = 0;
        while(start < end) {
            if(numbers[start] + numbers[end] > target) end--;
            else if(numbers[start] + numbers[end] < target) start++;
            else {
                if(nums[start] + nums[end] < min_product) {
                    find_flag = true;
                    min_product = nums[start] + nums[end];
                    a1 = nums[start];
                    a2 = nums[end];
                }
                left++;
            }
        }
        if(find_flag) return {a1, a2};
        return {};
    }
};

/*扩展
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
输出描述:
输出所有和为S的连续正数序列（指1、2、3、4等）。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
*/
class Solution{
public:
    vector<vector<int>> FindContinueSequence(int sum) {
        vector<vector<int>> res;
        if(sum < 3) return res;
        int left = 1, right = 2; //从序列1开始
        while(left < right) {
            int cursum = (left+right)*(right-left+1)/2;//用等差数列的求和公式
            if(cursum < sum)right++;
            else if(cursum > sum) left++;
            else {
                vector<int> temp;
                for(int i = left; i <= right; i++) {
                    temp.push_back(i);
                }
                res.push_back(temp);
                left++; //继续寻找下一个元素
            }
        }
        return res;
    }
};