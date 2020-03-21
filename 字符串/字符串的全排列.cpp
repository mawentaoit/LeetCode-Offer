/**
 * 问题：全排列（含重复元素，且要求按字典序输出)
 * 方法一：交换法，递归
 * 用哈希表记录，以解决在重复元素的全排列问题，参考问题总结
 */
class Solution{
public:
    vector<string> Permutation(string str) {
        vector<string> result;
        if(str.empty()) return result;
        per(str, 0, )
    }
};

/**
 * 方法二：dfs(掌握)
 * 用map记录，以解决存在重复元素的全排列问题
 */
class Solution{
public:
    vector<string> res;
    if(str.empty()) return res;
    string path;
    map<char, int> counter; //
};