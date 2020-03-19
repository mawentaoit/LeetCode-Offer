/*hash_map 思想
时间复杂度O(n);
空间复杂度O(n)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        if(len < 2) return {};
        unordered_map<int, int> mp;
        for(int i = 0; i < len; i++){
            if(mp.find(target- nums[i]) == mp.end()) mp[nums[i]] = i;
            else {
            return {mp[target-nums[i]], i};                
            }
        }
        return {};
    }
};
