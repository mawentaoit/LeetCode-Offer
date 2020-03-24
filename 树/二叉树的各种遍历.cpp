//前序遍历
void preorder(TreeNode* root, vector<int> &path) {
    if(root == nullptr) return ;
    path.push_back(root->val);
    preorder(root->left, path);
    preorder(root->right, path);
}
//中序遍历
void inorder(TreeNode* root, vector<int> &path){
    if(root == nullptr) return;
    inorder(root->left, path);
    path.push_back(root->val);
    inorder(root->right, path);
}
//后续遍历
void postorder(TreeNode* root, vector<int> &path) {
    if(root == nullptr) return;
    postorder(root->left, path);
    postorder(root->right, path);
    path.push_back(root->val);
}
//非递归遍历
/**
 * 前序遍历（根-左-右）
 * 根据前序遍历访问的顺序，优先访问根结点，然后再分别访问左结点和右节点，对于任一结点，其可看作是
 * 根节点，因此可以直接访问，访问完之后，若其左节点不为空，按相同规则访问它的左子树；
 * 当访问其左子树时，再访问它的右子树。
 * 对于任一结点P:
 * 1）访问结点p,并将结点p入栈；
 * 2)判断结点P的左孩子是否为空，若为空，则取顶节点并进行出栈操作，并将栈顶结点的右孩子置为当前的结点P
 */
class Solution{
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> path;
        if(root == nullptr) return path;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while(p || !s.empty()) {
            if(p){
                path.push_back(p->val);
                s.push(p); //入栈
                p = p->left;
            }else{
                p = s.top();
                s.pop();
                p = p->right; //指向右结点
            }
        }
        return path;
    }
};

/**
 * 中序遍历：（左根右）
 * 根据中序遍历的顺序，对于任一结点，优先访问其左孩子，而左孩子结点又可以看做一根节点
 * 然后继续访问其左孩子结点，直到遇到左孩子结点为空的结点才进行访问，然后按相同的规则访问其右子树
 * 对于任一结点P
 * 1)若其左孩子不为空，则将P入栈并将P的左孩子置为当前的P,然后对当前结点P再进行相同的处理
 * 2)若其左孩子为空，则取栈顶元素并进行出栈操作，访问该栈顶结点，然后将当前的P置为栈顶结点的右孩子
 * 3）直到P为NULL并且栈为空则遍历结束
 */
class Solution{
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> path;
        if(root == nullptr) return path;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while(p || !s.empty()) {
            if(p) {
                s.push(p);//入栈
                p = p->left;
            }else {
                p = s.top();
                path.push_back(p->val); //访问栈顶元素
                s.pop();
                p = p->right;
            }
        }
        return path;
    }
};
/**
 * 后续遍历（左-右-根）
 * 要保证根节点在左孩子和右孩子访问之后才能访问，因此对于任一结点P，先将其入栈。
 * 1) 如果P不存在左孩子和右孩子，则可以直接访问它
 * 2) 或者P存在左孩子和右孩子，但是其左孩子和右孩子都已经被访问过了，则同样可以直接访问该结点
 * 3) 若非上诉两种情况，则将P的右孩子和左孩子依次入栈，这样就能保证了每次取栈顶元素的时候，左孩子在右孩子前面被访问。
 */



//层次遍历
//方法一：递归法O(n), O(1)
class SOlution{
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        traverse(root, 1, res);
        return res;
    }
    void traverse(TreeNode* root, int level, vector<vector<int>>& res) {
        if(root == nullptr) return; //递归的出口
        if(level > res.size()) {
            res.push_back(vector<int>()); //在下一层时，增加空容器
        }
        res[level-1].push_back(root->val); //将元素的值push进level层的容器
        traverse(root->left, level+1, res);
        traverse(root->right, level+1， res);//最后一个语句return之后，整个递归函数才结束
    }
};

/**
 * 迭代法，O(n),O(1)掌握
 * 层序遍历二叉树是典型的广度优先搜索BFS的应用，但是这里稍微复杂一点的是，我们要把各个层的数分开，存到一个二维向量里面
 * 用队列实现
 * 1)首先根结点入队
 * 2)访问队首元素，队首元素出队，若子节点不为空，子节点(下一层的所有结点)入队
 * 3)一层一层的访问，直至队列清空
 */
class Solution{
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root); //根结点入队
        while(!q.empty()) {
            vector<int> level;
            int size = q.size(); //当前层的节点数，会随着每层结点的push,长度会发生变化
            for(int i = 0;i < size; i++) //遍历该层结点，并将下一层结点入队
            {
                TreeNode* node = q.front();
                level.push_back(node->val); //访问当前结点
                q.pop(); //出队
                //将当前结点的左右子结点入队
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(level);
        }
        return res;
    }
};

/**
 * z字性打印二叉树
 */
//用level-order遍历，用奇数层偶数层判断，偶数层时方向存数
class Solution{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res; //创建包含子容器的容器
        traverse(root, 1, res);
        return res;
    }

    //递归函数的功能，按zigzag Level Order扫描某一层的元素，存在一个vector里
    void traverse(TreeNode* root, int level, vector<vector<int>>& res) {
        if(root == nullptr) return; //递归子函数和递归母函数的出口
        if(level > res.size()) res.push_back(vector<int>());//增加子容器
        //每一个结点都可以看成本层的根节点，将当前层(第level层)的结点元素push进vector里
        if(level % 2 == 1) {
            res[level-1].push_back(root->val);
        }else { //下一层为偶数层时，反向存数
            res[leve-1].insert(res[level-1].begin(), root->val);//在开头插入数据
        }
        //从左到右存数
        traverse(root->left, level+1, res);
        traverse(root->right, level+1, res);
    }
};

/**
 * 方法二：迭代法
 * 按level order遍历，偶数层时翻转一下(可以用bool型变量，每一层反号一次)
 */
class Solution{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        queue<TreeNode* > q;
        q.push(root); /根结点入队
        bool right_to_left = false;
        while(!q.empty()) {
            vector<int> level;
            int size = q.size(); //当前层的结点数
            for(int i = 0;i < size; i++) {
                TreeNode* node = q.front();
                level.push_back(node->val); //访问当前结点
                q.pop(); //出队
                //将当前结点的左右子结点入队
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(right_to_left) reverse(level.begin(), level.end());//反序
            res.push_back(level);
            right_to_left = !right_to_left;
        }
        return res;
    }
};
//二叉树的竖直遍历
// class Solution{
// public:
//     vector<vector<int>> verticalOrder(TreeNode* root) {
//         vector<vector<int>> res;
//         if(root != nullptr) return res;
//         map<int, vector<int>> m; //构建存储<序号，遍历序列>对的map
//         queue<pair<int, TreeNode*>> q; //构建存储<序号，结点>对的队列

//     }
// };