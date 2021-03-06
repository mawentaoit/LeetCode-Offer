/**
 * 最佳情况O(logn), 最坏情况是O(n)
 * 1  BST的查找是从根结点开始，若二叉树非空，将给定值与根节点的关键字比较,
 * 若相等，则查找成功，
 * 若不等，则比较查找查找结点值与当前结点值大小，当给定值小于当前结点值时，在当前结点左子树中查找，否则在右子树中查找
 */
/**
 * 递归查找
 */
Node* BST_Serach(BSTree T, int k) {
    if(T == nullptr || k == T->key) return T;
    if(k < T->key) return BST_Serach(T->left, k);
    else return BST_Serach(T->right, k);
}

