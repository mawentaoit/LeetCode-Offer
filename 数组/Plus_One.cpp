/*
问题：数组加一，高位在前，低位在后
考虑进位情况
*/
class Solution{
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size() - 1; i >= 0; i--) {
            if(digits[i] == 9) digits[i] = 0; //如果为9，置为0，下次进位
            else {
                digits[i]++;
                return digits;
            }
        }
        digits[0] = 1;
        digits.push_back(0); //补充一位
        return digits;
    }
};