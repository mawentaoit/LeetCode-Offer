//用中序遍历迭代法做
//二叉树查找树性质：中序遍历后，二叉查找树为升序排列
class Solution{
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        stack<TreeNode*> s;
        TreeNode* p = root;
        TreeNode* pre = nullptr;
        while(!s.empty() || p) {
            if(p) {
                s.push(p);
                p = p->left;
            }else {
                p = s.top();
                if(pre != nullptr && p->val <= pre->val) return false;
                pre = p;
                s.pop();
                p = p->right;
            }
        }
        return true;
    }
};