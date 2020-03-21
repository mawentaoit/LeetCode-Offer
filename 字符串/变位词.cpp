/**
 * 问题：字谜/变位词(判断某个字符串是否可以组合成某一个单词，假设只有小写)
 * 方法一：排序之后看是否一样
 * O(nlogn) O(1)
 */
class Solution{
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return (s==t);
    }
};
//法2：
//统计表法，如果key值分布比较散，比如包含unicode字符，可以考虑用hash表
//O(n), O(1)
class Solution{
public:
    bool isAnagram(string a, string t) {
        if(a.size() != t.size()) return false;
        int counter[26] = {0}; //26个小写英文字母
        for(int i = 0; i < a.size(); i++) {
            counter[s[i] - 'a']++;//也可用两个统计表分别统计，最后比较两个统计表是否相等
            counter[t[i] - 'a']--;   
        }
        for(int count : counter) {
            if(count != 0) return false;
        }
        return true;
    }
};


/**
 * 扩展
 * 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
*/
/**
 * 法1：用hash表map
 */
class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string s : strs) {
            string t = s;
            sort(t.begin(), t.end()); //key值，字谜单词排序后key值相同
            mp[t].push_back(s);
        }
        vector<vector<string>> res;
        for(auto& m : mp) {
            res.push_back(m.second); //用.second访问map中的键值
        }
        return res;
    }
};
/**
 * 方法二：同统计表实现，用单词的统计比(可以用vector,长度为26)作为key值
 * O(nk), O(nk)
 */
class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, multiset<string>> mp;
        for(string s : strs) {
            string t = strSort(s);
            mp[t].insert(s);
        }
    }
private:
    string strSort(string& s) {
        int count[26] = {0}, n = s.length();
        for(int i = 0; i < n; i++) {
            count[s[i] - 'a']++; //相当于计数排序
        }
        int p = 0;
        string t(n,'a');
        for(int j = 0; j < 26; j++) {
            for(int i = 0; i < count[j]; i++) {
                t[p++] += j;
            }
        }
    }
};