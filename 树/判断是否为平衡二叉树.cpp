 /**
 * 对于每一个节点，我们通过checkDepth方法递归获得左右子树的深度
 * 如果子树是平衡的，则返回真实的深度，若不平衡，直接返回-1，
 * 此方法时间复杂度为O(N),空间复杂度O(H)
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
         if(checkDepth(root) == -1) return false;
         else return true;     
    }
private:
    int checkDepth(TreeNode* root) {
        if(!root) return 0; //为空时，返回深度0
        int left = checkDepth(root->left);
        if(left == -1) return -1;
        int right = checkDepth(root->right);
        if(right == -1) return -1;
        int diff = abs(left - right);
        if(diff > 1) return -1;
        else return 1 + max(left, right);
    }
};