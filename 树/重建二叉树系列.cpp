/**
 * 给定中序遍历和前序遍历，且无重复元素，则可以从根节点(前序遍历第一个结点)找起
 * 再找左子树和右子树
 */
class Solution{
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildOneLevel(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1); 
    }
    //递归函数的功能：
    TreeNode* buildOneLevel(vector<int>& preorder, int pre_begin, int pre_end, vector<int>& inorder, int in_begin, int in_end) {
        if(pre_begin > pre_end || in_begin > in_end) return nullptr;
        //先找到根节点(用前序遍历序列) 
        TreeNode* root = new TreeNode(preorder[pre_begin]);
        //在找左子树和右子树(用中序遍历序列)
        int left_length = 0; //左子树长度
        for(int i = in_begin; i <= in_end; i++) {
            if(inorder[i] == root->val) {
                left_length = i;
                break; //先找到中序遍历
            }
        }
        left_length -= in_begin; //左子树长度
        root->left = buildOneLevel(preorder, pre_begin+1,pre_begin+left_length,
        inorder, in_begin, in_begin+left_length-1);
        root->right = buildOneLevel(preorder, pre_begin+left_length+1, pre_end,
        inorder, in_begin+left_length+1, in_end);
        return root;
    }
};

class Solution{
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildOneLevel(preorder.begin(), preorder.end(), inorder.begin()); //注意end指向末尾容器
    }
    using iter = vector<int>::iterator;
    TreeNode* buildOneLevel(iter pre_begin, iter pre_end, iter in_begin, iter in_end) {
        if(pre_begin == pre_end || in_begin == in_end) return nullptr;
        //先找根节点
        TreeNode* root = new TreeNode(*pre_begin); //前序遍历列首元素即为根节点
        //在找左子树和右子树(用中序遍历序列)(具体只用求左子树序长度就可以了)
        vector<int>::iterator in_root_pos = find(in_begin, in_end, root->val);
        int left_length = in_root_pos - in_begin; //左子树序列长度
        root->left = buildOneLevel(pre_begin+1, pre_begin+left_length+1, in_begin, in_root_pos);
        root->right = buildOneLevel(pre_begin+left_length+1, pre_end, in_root_pos+1, in_end);
        return root;
    }
};

//通过后续和中序遍历构建二叉数
