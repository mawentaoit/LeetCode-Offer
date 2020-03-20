/*
问题：有序数组总结范围(无重复数)
方法：扫描数组，用双指针找范围的左右端点
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.empty())  return res;
        for(int i = 0; i < nums.size(); ){
            int left = i; //i=0~n-1
            int right = i;
            while(right + 1<nums.size() && nums[right+1] == nums[right]+1) right++;
            if(right == left) //范围等于1时
                res.push_back(to_string(nums[right]));
            else //范围大于1时
                res.push_back(to_string(nums[left] + "->" + to_string(nums[right])));
            i = right + 1; //移动到当前范围的后一个元素
        }
        return res;
    }
};