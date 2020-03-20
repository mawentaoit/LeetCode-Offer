/**
 * 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
 * eg: s = "leetcode" return 0;
 * eg: s = "loveleetcode" return 2;
 */

//法1：空间换时间
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        for(int i = 0; i < s.size(); i++) {
            if(mp[s[i]] == 1) return i;
        }
        return -1;
    }
};