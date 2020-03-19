/**
 * 问题：去除有序序列中的重复数字
 * 方法一：双指针法(覆盖法)
 * 当a[i] != a[index-1] 用a[i] 覆盖a[index]
 * 相等时不覆盖，不相等时，index代表了新数组的索引，i代表了旧数组的索引，将无重复数字依次移动到前面
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return len;
        int index = 0;
        int i = 1;
        while(i < len) {
            if(nums[i] == nums[index]) i++;
            else {
                nums[++index] = nums[i++];
            }
        }
        return index+1;
    }
};
/**
 * 问题：移除排序数组的重复项，每个数据最多可以出现两次
 * 覆盖法:
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len < 3) return len;
        int index = 2;
        for(int i = 2; i < len; i++){
            if(nums[index-2] != nums[i]) {
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};
