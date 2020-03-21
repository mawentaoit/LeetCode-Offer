/**
 * Example:
Given s = "hello", return "olleh".
*/
class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        if(len < 2) return ;
        int start = 0;
        int end = len -1;
        while(start < end) {
            swap(s[start++], s[end--]);
        }
    }
};