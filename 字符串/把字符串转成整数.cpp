/**
 * 题目描述：将一个字符串转换成一个整数，要求不能使用字符串转换成整数的库函数
 * 数值为0或者字符串不是一个合法的数值则返回0
 */
/**
 * 本题没有考虑前面有空格的情况，与leetcode中题目有点不同，而且把1a33这样的字符也当做异常，不会输出1
 * 1. 处理正负号
 * 2. 处理数字
 * 3. 处理溢出
 * 4. 处理夹杂异常字符的情况
 */
class Solution{
public:
    int StrToInt(string str) {
        if(str.empty()) return 0; //处理异常情况
        int sign = 1; //初始化符号
        int i = 0;
        if(str[i] == '-') //处理正负号{
            sign = -1;
            i++;
        }else if(str[i] == '+') i++;

        long long num = 0; //long long 不管在32位机还是64位机均为64位
        for(; i < str.size() && str[i] >= '0' && str[i] <= '9'; i++) {
            int digit = str[i] - '0';
            num = num*10 + digit;
            //处理溢出问题
            if((sign > 0 && num > INT_MAX) || (sign<0 && -num < INT_MIN)) {
                num = 0;
                break;
            }
        }
        if(i < str.size()) num = 0; //说明从中途退出，有异常字符
        return num*sign;
    }
};