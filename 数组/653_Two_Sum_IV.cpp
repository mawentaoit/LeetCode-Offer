/*思想一:
把搜索二叉树中序遍历并存入容器中，这时容器是排序的
利用对撞指针即可求解
时间复杂度O(n)
空间复杂度O(n)
*/
class Solution {
public:
    void getValue(TreeNode* root, vector<int>& res) {
        if(root == nullptr) return;
        getValue(root->left,res);
        res.push_back(root->val);
        getValue(root->right, res);
    }
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr) return false;
        vector<int> nums;
        getValue(root, nums);
        int len = nums.size();
        int start = 0;
        int end = len -1;
        while(start < end) {
            if(nums[start] + nums[end] > k) end--;
            else if(nums[start] + nums[end] < k) start++;
            else return true;
        }
        return false;
    }
};