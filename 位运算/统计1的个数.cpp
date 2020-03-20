/**
 * 题目描述:二进制中1的个数
 * 解法1：利用减1在做与运算可以使最右边的1变为0，统计1的个数
 */
class Solution{
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){ //有几个1就运算几次，比方法二效率高
            count++;
            n = (n-1)&n; //通过减1再做与运算可以使最右边的1变为0，不断重复可以统计1的个数
        }
        return count;
    }
};
//解法2:依次和1，10，100...10000000做与运算
class Solution{
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        unsigned int mask = 1; //32位无符号数
        while(mask) {
            if(n & mask) count++;
            mask = mask << 1; //左移一位
        }
    }
};