/**
 * 问题：实现strstr函数，字串查找(子串匹配)
 * 法1：扫描主串，再扫描字串，O(mn)
 */
class Solution{
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if(n == 0) return 0; //如果neelde为空
        for(int i = 0; i <= m-n; i++) {
            int j = 0;
            for(; j < n; j++) {
                if(haystack[i+j] != needle[j]) break; //如果有某个字符不匹配退出循环
            }
            if(j == n) return i; //如果匹配返回其实索引
        }
    }
};
//KMP算法
