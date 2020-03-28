/**
 * 后续遍历序列规律：最后一个元素为根节点，前面左半部分为左子树，右半部分为右子树
 * BST规律：对于任意节点，作结点<根节点<右节点
 * 根绝这两个规律进行判断
 */
class Solution{
public: 
    bool VerifySquenceOfBST(vector<int>& sequence) {
        if(sequence.empty()) return false;
        return verify(sequence, 0, sequence.size() - 1);
    }
private:
    bool verify(vector<int>& a, int begin, int end) {
        if(begin >= end) return true; //只有一个元素了
        int root = a[end]; //根节点
        //计算左子树序列的长度
        int i = begin;
        for(; i < end-1; i++) {
            if(a[i] > root) break;
        }
        //判断右子树序列是否满足大于根节点的规律
        for(int j = i; j < end-1; j++) {
            if(a[j] < root) return false; //若右子树不满足规律，则返回false
        }
        //判断左子树和右子树是否为二叉搜索树
        return verify(a, begin, i-1) && verify(a, i, end-1);
    }
};