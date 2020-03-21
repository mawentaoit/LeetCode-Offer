/**
 * 问题：atoi字符串转数字函数实现
 * 要求：先检测第一个非空格字符，然后识别"+"或"-",将后面的数字字符翻译为数字，终止于
 * 非数字字符
 * 数值范围[-2^31, 2^31-1] 即[INT_MIN, INT_MAX]
 */
class Solution{
public:
    int myAtoi(string str) {
        int sign = 1; //符号
        long long base = 0; //结果
        int i = 0; //用于遍历字符串
        if(str.empty()) return 0;
        while(str[i] == ' ') i++; //跳过空格
        if(str[i] == '+' || str[i] == '-') //翻译正负号
        {
            sign = (str[i] == '-') ? -1 : 1;
            i++;
        }
        while(str[i] >= '0' && str[i] <= '9') //数字字符才进入循环
        {
            int digit = str[i] - '0';//翻译数字字符
            base = 10*base + digit;
            //处理可能的溢出情况
            if((sign>0 && base>INT_MAX) || (sign<0 && -base<INT_MIN)){
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            i++;
        }
        return sign*base;
    }
};