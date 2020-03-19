/**
 * 问题：求两个数组的交集(不能有重复的数)
 * 方法1：hash表法，用set避免重复 O(n) O(n)
 */
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {    
        set<int> record;
        for(int i = 0; i < nums1.size(); i++) {
            record.insert(nums1[i]);
        }
        set<int> resultSet;
        for(int i = 0; i < nums2.size(); i++){
            if(record.find(nums2[i]) != record.end()){
                resultSet.insert(nums2[i]);
            }
        }
        vector<int> resultVector;
        for(auto iter : resultSet) 
            resultVector.push_back(iter);
        return resultVector;
    }
};
//法2：先排序,时间换空间O(nlogn),O(1) 
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {    
       if(nums1.empty() || nums2.empty()) return {};
        vector<int> res;
        int i = 0, j = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while(i < nums1.size() && j < nums2.size()) //从起始位置开始分别扫描两个数组
        {
            if(nums1[i] < nums2[j]) i++; //递增第一个数组的指针
            else if(nums1[i] > nums2[j]) j++; //递增第二个数组的指针
            else {
                if(res.empty() || res.back() != nums1[i]) //如果为空或者不重复时才push交集元素
                {
                    res.push_back(nums1[i]);
                }
                i++, j++;
            }
        }
        return res;
    }
};

/**
 * 扩展：计算两个数组的交集(交集中元素与顺序无关，不是指公共子数组)
 * 可以返回重复的数
 */
//法1：hash表
//构建hash表计数器，依nums在计数器中出现的次数，如果出现了，就push元素，计数器对应值减1
//分析O(m+n),O(m)
class Solution{
public:
    vector<int> intersect(vector<int>& num1, vector<int>& num2) {
        unordered_map<int, int> counter;
        vector<int> res;
        for(int num: num1) counter++;  //统计每个数字出现的次数
        for(int num: num2) {
            if(counter.find(num) != counter.end() && counter[num] >= 1) {
                counter[num]--;
                res.push_back(num);
            }
        }
        return res;
    }
};

//法2：排序后再找
//时间换空间
class Solution{
public:
    vector<int> intersect(vector<int>& num1, vector<int>& num2) {
        if(num1.empty() || num2.empty()) return {};
        vector<int> res;
        int i = 0, j = 0;
        sort(num1.begin(), num2.end());
        sort(num2.begin(), num2.end());
        while(i < num1.size() && j < num2.size()) { //i,j分别用来遍历两个数组
            if(num1[i] < num2[j]) i++;
            else if(num1[i] > num2[j]) j++;
            else {
                res.push_back(num1[i]);
                i++, j++; //同时递增两个数组指着
            }
        }
        return res;
    }
};