/**
 * 问题:找到数组中和为0的三元组
 * 方法：排序后，扫描数组，转化为2sum问题
 * 2sum对应一个循环，3sum对应两个循环，4sum对应三个循环
 *时间复杂度O(n^2)
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        if(len < 3) return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len && nums[i] <= 0; i++) { //这里做了一个优化如果nums[i]不小于等于0那么后面的元素肯定不会成立
            int target = -nums[i]; //将第一个数的相反数定位2sum的target
            int left = i+1;
            int right = len-1;
            while(left < right) {
                int sum = nums[left] + nums[right];
                if(sum < target) left++;
                else if(sum > target) right--;
                else { //满足3sum要求
                    res.push_back({nums[i], nums[left], nums[right]}); 
                    while(left < right && nums[left+1] == nums[left]) left++; //以免第二个数重复
                    while(left < right && nums[right] == nums[right-1]) right--; //以免第三个数字重复
                    left++; //前后指针都移动，下一次判断
                    right--;
                }
            }
            while(i+1 < len && nums[i+1] == nums[i]) i++; //以免第一个数重复
        }
        return res;
    }
};

/**
 * 问题二：离目标最近的三数之和
 * 方法：排序后，扫描a[i],后面在用left和right首尾两指针扫描
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        if(len < 3) return -1;
        int closest = nums[0] + nums[1] + nums[2]; //随便找到一个
        int diff = abs(closest-target);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len; i++) {
            int tar = target-nums[i];
            int left = i+1;
            int right = len - 1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int newDiff = abs(sum - target);
                if(newDiff < diff) {
                    diff = newDiff;
                    closest = sum;
                }
                if(sum < target) left++; //调节指针
                else right--;
            }
        }
        return closest;
    }
};

/**
 * 4sum问题
 * 问题：找出与目标值相等的4个数
 * 三重循环即可
 * 用set可避免重复结果
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        if(nums.size() < 4) return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        //扫描nums[i], nums[j]后面接left, right两个指针
        for(int i = 0; i < len-3; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < len - 2; j++) {
                if(j > i+1 && nums[j] == nums[j-1]) continue;//遇到重复直接跳过
                int left = j+1;
                int right = len - 1;
                while(left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum < target) left++;
                    else if(sum > target) right--;
                    if(sum == target) {
                       vector<int> temp{nums[i], nums[j], nums[left], nums[right]}; 
                        res.push_back(temp);
                        while(left < right && nums[left+1] == nums[left]) left++; //以免第二个数重复
                        while(left < right && nums[right] == nums[right-1]) right--; //以免第三个数字重复
                        left++;
                        right--;
                    }
                }
            }
        }
        return res;
    }
};