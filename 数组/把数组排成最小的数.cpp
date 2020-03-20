/**
 * 题目描述：输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323
 */
/**
 * 思路：定义新的大小关系，对vector容器内的数据进行排序
 * 按照将a和b转为string后
 * 若 a+b < b+a a 排在b之前的规则排序
 * 如 2 21 因为 21 2 < 2 21所以，排序后为212
 * to_string()可以将int转化为string,方便组合后比较，不用管各数的位数
 * 时间复杂度O(nlogn)
 */
class Solution{
public:
    static bool cmp(int a, int b) //必须定义成static类型才能被sort使用
    {
        string A = to_string(a) + to_string(b);
        string B = to_string(b) + to_string(a);
        return A < B; //利用字符串的比较方法
    }
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(), numbers.end(), cmp); //用自定义的排序方法从小到大进行排序
        string res;
        for(auto iter : numbers) res += to_string(iter);
        return res;
    }
};