/**
 * 输入n个整数，找出其中最小的k个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1，2，3，4
 */
class Solution{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(k <= 0 || k > input.size()) return vector<int>(); //处理非法输入
        nth_element(input.begin(), input.begin()+k-1, input.end());
        vector<int> result(input.begin(), input.begin()+k); //构造结果向量
        return result;
    }
};
/**
 * 掌握
 * 方法一：基于parition(快排中有用到，stl中也有，但是还是自己实现较好)
 * 多次partition直到枢纽位置为k即可
 */
class Solution{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(input.empty() || k <= 0 || k > input.size()) return vector<int>(); //处理异常输入
        int left = 0, right = input.size() - 1;
        int pivot_pos;
        while(left <= right) //类似二分查找法
        {
            pivot_pos = partition(input, left, right);
            if(pivot_pos < k-1) 
                left = 
        }
    }
};