class Solution{
public:
    int reverse(int x) {
        //int 反转最大也不超过用33位
        long long res = 0; //保证即使在32位系统中变量也为64位，比int位宽大
        long long t = x;//中间变量

        t = t > 0? t : -t; //取绝对值
        while(t>0){
            res = res*10 + t%10;
            t /= 10; //t除以10再模10就能依次获得各位数字
        }
        //判断符号
        if(x > 0) { //处理溢出情况
            if(res > INT_MAX) return 0;
            else return res;
        }
        else {
            res = -res;
            if(res < INT_MIN) return 0;
            else return res;
        }
    }
};