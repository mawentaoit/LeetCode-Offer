/**
 * 题目：数组中出现的次数超过数组长度的一半，请找出这个数字
 */
//法1：hash表 O(n),O(n)
class Solution{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        unordered_map<int, int> counter;
        int k = numbers.size() / 2;
        for(int it : numbers) {
            counter[it]++; //构建计数器
            if(counter[it] > k) return it; //优化
        }
        return 0;
    }
};
//法2：消除法O(n), O(1)
class Solution{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int res = numbers[0];
        int time = 1;
        for(int i = 1; i < numbers.size(); i++) {
            if(time == 0) { //全部消完，选举一个数
                res = numbers[i];
                time = 1;
            }
            else if(numbers[i] == res) time++; //等于增加1
            else time--; //不等消去1
        }
        time = 0;
        for(int it : numbers) {
            if(it == res) time++;
        }
        if(time > numbers.size() / 2) return res;
        else return 0; //不存在
    }
};