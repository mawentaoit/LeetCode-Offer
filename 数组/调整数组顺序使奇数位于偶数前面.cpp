/*题目描述：调整数组使奇数位于偶数后面
*/
//法1：一个游标指向奇数的后一个位置，另一个游标往后遍历，遍历到奇数就进行交换
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return nums;
        int left = 0;
        for(int i = 0; i < len; i++) {
            if(nums[i]%2) {
                swap(nums[left++], nums[i]);
            }
        }
        return nums;
    }
};
//法2：双指针
//一个游标指向奇数后一个位置并且确定是一个偶数，一个游标从后往前指向一个偶数前面的位置，并且确定是一个奇数，进行交换
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return nums;
        int left = 0;
        int right = len-1;
        while(left < right) {
            while(left < right && nums[left]%2 != 0) left++;
            while(left < right && nums[right]%2 == 0) right--;
            swap(nums[left], nums[right]);
        }
        return nums;
    }
};
