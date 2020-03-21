//问题：各字符串最长公共前缀
class Solution{
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return ""; //返回空串
        if(strs.size() == 1) return strs[0]; //返回自身
        string res = strs[0]; //初始化
        int length = res.size(); //公共前缀的长度
        for(int i = 1; i < strs.size(); i++)//从第二个单词开始遍历
        {
            int temp = -1;
            for(int j = 0; j <length && j <strs[i].size(); j++) {
                if(str[i][j] == res[j]) temp = j; //保存当前索引
                else break;
            }
            length = temp + 1;
        }
        res[length] = '\0';//打上结束字符
        return res;
    }
};