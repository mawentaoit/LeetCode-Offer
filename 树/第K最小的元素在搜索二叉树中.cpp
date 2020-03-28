/**
 * 中序递归法：
 */
class Solution{
public:
    int kthSmallest(TreeNode* root, int k ) {
        vector<int> nodes;
        inorder(root, nodes);
        return nodes[k-1];
    }
    void inorder(TreeNode* root, vector<int>& nodes) {
        if(root == nullptr) return;
        inorder(root->left, nodes);
        nodes.push_back(root->val);
        inorder(root->right, nodes);
    }
};
/**
 * 方法二：中序遍历迭代法
 * 在遍历的过程中统计数量
 */
class Solution{
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        stack<TreeNode*> s;
        while(!s.empty() || p) {
            if(p) {
                s.push(p); //入栈
                p = p->left; //指向下一个左节点
            }
        }else
        {
            p = s.top();
            cnt++;
            if(cnt == k) return p->val;
            s.pop();
            p = p->right; //指向右节点
        }
        return 0;
    }
};
/** 方法三：分治法
 * 首先计算出左子树的节点个数总和cnt,
 * 如果k小于等于左子树节点总和cnt,说明第k小的元素在左子树中，直接对左子树节点调用递归即可
 * 如果k大于cnt+1,说明目标值在右子树中，对右子树节点调用递归函数
 * 如果k等于cnt+1,则当前结点即为所求
 */
class Solution{
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = count(root->left);
        if(k <= cnt) {
            return kthSmallest(root->left, k);
        }
        else if(k > cnt+1) {
            return kthSmallest(root->right, k - cnt - 1);
        }
        else 
            return root->val;
    }
    int count(TreeNode* node) {
        if(!node) return 0;
        return 1 + count(node->left) + count(node->right);
    }
};

/**
 * Follow up:假设该BST被修改的很频繁，而且查找第k小元素的操作也很频繁，问我们如何优化
 * 方法：改进方法三：
 * 修改原树结点的结构，使其保存当前结点和其左右子树所有结点的个数，
 * 这样我们使用的时候就可以快速得到任何子树结点总数来帮我们快速定位目标值了
 */
class Solution{
private:
    struct MyTreeNode
    {
        int value;
        int count;
        MyTreeNode* left;
        MyTreeNode* right;
        MyTreeNode(int x) : val(x), count(1), left(nullptr), right(nullptr) {
        }
    };
public:
    int kthSmllest(TreeNode* root, int k) {
        MyTreeNode* node = build(root);
        return helper(node, k);
    }
    MyTreeNode* build(TreeNode* root) {
        if(!root) return nullptr;
        else {
            MyTreeNode* node = new MyTreeNode(root->val);
            node->left = build(root->left);
            node->right = build(root->right);
            if(node->left) node->count += node->left->count;
            if(node->right) node->count += node->right->count;
            return node;
        }
    }

    int helper(MyTreeNode* node, int k) {
        if(node->left) {
            int cnt = node->left->count; //左结点存储了当前结点左子树的所有结点
            if(k <= cnt) return helper(node->left, k);
            else if(k > cnt + 1) 
            return helper(node->right, k-1-cnt);
            else return node->val;
        }else {
            if(k == 1) return node->val;
            else return helper(node->right, k-1);
        }
    }
    
};