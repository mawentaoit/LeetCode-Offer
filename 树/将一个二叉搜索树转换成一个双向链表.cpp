class Solution{
public:
    TreeNode* Convert(TreeNode* root) {
        if(root == nullptr) return nullptr;
        TreeNode* head = root;
        while(head->left) head = head->left;
        stack<TreeNode*> s;
        TreeNode* p = root, *pre = nullptr;
        while(p || !s.empty()) {
            if(p) {
                s.push(p);
                p = p->left;
            }else {
                p = s.top();
                p->left = pre; //连接p与pre
                if(pre) pre->right = p; //连接pre与p
                pre = p; //更新pre
                s.pop();
                p = p->right;
            }
        }
        return head;
    }
};

// /**
//  * 方法二：中序遍历递归法(左，根，右)
//  */
// class Solution{
// private:
//     TreeNode* pre;
// public:
//     TreeNode* Convert(TreeNode* pRootOfTree) {
//         if(pRootOfTree == nullptr) return nullptr;
//         pre = nullptr;
//     }
// };