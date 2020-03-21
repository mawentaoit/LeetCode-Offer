/**
 * 问题：回文（判断一个字符串是否回文，这里仅考虑字母数字字符，且忽略大小写
 * 方法：双指针法，分别从开头和结尾扫描
 */
class Solution{
public:
    bool isPalindrome(string s) {
        for(int i = 0, j = s.size()-1; i < j; i++, j--) {
            while(isalnum(s[i]) == false && i < j) i++; //
            while(isalnum(s[i]) == false && i < j) j--;
            if(toupper(s[i]) != toupper(s[j])) return false;//如果不匹配就退出            
        }
        return true;
    }
};
/**
 * 问题：回文2（判断一个字符串是否是回文，可以最多删除一个字符，而且字符串中只有小写英文字母，最大长度为50000)
 * 方法：双指针，借用回文1的解法
 */
class Solution {
public:
    bool validPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        while(start < end) {
            if(s[start] != s[end]) {
                int i1 = start, j1 = end-1;
                int i2 = start+1, j2 = end;
                while(i1 < j1 && s[i1] == s[j1]) {
                    i1++;
                    j1--;
                }
                while(i2 < j2 && s[i2] == s[j2]) {
                    i2++;
                    j2--;
                }
                return i1 >= j1 || i2 >= j2;
            }
            start++;
            end--;
        }
        return true;
    }
};