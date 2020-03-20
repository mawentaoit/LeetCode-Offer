/**
 * 问题：将数组中0元素移至后面，且保持非0元素相对顺序
 * 原地操作，不要使用复制数组
 * 方法：双指针法
 */
class Solution{
public:
    void moveZero(vector<int>& nums) {
        for(int left = 0, right = 0; right < nums.size(); right++) {
            if(nums[right] != 0) { //如果遇到非零元素就移动到前面，并更新非零元素指针
                swap(nums[left++], nums[right]);
            }
        }
    }
};