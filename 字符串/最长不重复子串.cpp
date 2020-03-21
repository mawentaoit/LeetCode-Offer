//找出字符串中的最长无重复字符的子串
/**
 * 方法：滑动窗口
 */
class Solution{
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char> set; //用hash表存滑动窗口中的数,方便查找是否有重复的数
        int left = 0, right = 0;
        int max_length = 0;
        while(right < s.size()) {
            if(set.find(s[right]) == set.end()) {
                set.insert(s[right++]);
                max_length = max(max_length, int(set.size()));
            }
            else {
                set.erase(s[left++]); //移除左边元素，左指针加一
            }
        }
        return max_length;
    }
};