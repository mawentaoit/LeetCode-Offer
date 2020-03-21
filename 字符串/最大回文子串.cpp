/**
 * 问题：最长回文子串
 * 方法一：O(N^2),O(1)
 */
class Solution{
private:
int start;
int maxlen;
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if(len < 2) return s;
        start = 0;
        maxlen = 0;
        for(int i = 0;i < len; i++) { //扫描字符串，扫描到的字符作为回文的中心字符
            extendPalindroms(s, i, i); //假定奇数长度的子串，从中心扩展回文
            extendPalindroms(s, i, i+1); //假定偶数长度的子串，从中心两个元素扩展回文
        }
        return s.subsr(start, maxlen); 
    }
private:
    void extendPalindroms(string& s, int left, int right) {
        while(left >= 0 && right < s.size() && s[left] == s[right])//由中心向两边扩展
        {
            left--;
            right++;
        }
        if(right-left-1>maxlen){
            start = left + 1; //更新起点
            maxlen = right-left-1; //更新最大长度
        }
    }
};