/**
 * 从扑克牌中随机抽 5 张牌,判断是不是顺子,即这 5 张牌是不是连续的。 2-10 为数字本身,A 为 1,J 为 11,Q 为 12,K 为 13,而大小王可以看成任意的 数字。（大小王最多4张）
 */
/**
 * 1.排序
 * 2. 计算所有相邻数字间隔总数
 * 3.计算0的个数
 * 4.如果2，3相等，就是顺子
 * 5.如果出现对子，则不是顺子
 */
class Solution{
public:
    bool IsContinuous(vector<int> numbers) {
        if(numbers.empty()) return false;
        int num_of_zero = 0;
        int num_of_interval = 0;
        sort(numbers.begin(), numbers.end()); //排序
        for(int i = 0; i < numbers.size()-1; i++) {
            if(numbers[i] == 0) {
                num_of_zero++;
                continue; //继续循环
            }
            //如果存在对子，直接返回
            if(numbers[i] == numbers[i+1])
                return false;
            //统计间隔数量
            num_of_interval += numbers[i+1] - numbers[i] - 1;
        }
        if(num_of_zero >= num_of_interval) return true;
        else return false;
    }
};