/**
 * 反转字符串
 * 题目一：翻转单词顺序
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
*/
//法1：一个字符一个字符的处理，得到单词之后插入到结果字符前面
class Solution{
public:
    string ReverseSentence(string str) {
        string res, temp;
        for(char ch : str) {
            if(ch == ' '){
                res = ' ' + temp + res;
            }else {
                temp += ch; //构建单词
            }
        }
        if(temp.size()) res = temp + res;
        return res;
    }
};

void ReverseWord(string &str, int s, int e) {
    while(s < e){
        swap(str[s++], str[e--]);
    }
}
string ReverseSentence(string str) {
    ReverseWord(str, 0, str.size() - 1); //先整体翻转
    int left = 0, right = 0;
    int i = 0;
    while(i < str.size()) {
        while(i < str.size() && str[i] == ' ') //空格跳过
        i++;
        left = right = i; //记录单词的第一个字符的位置
        while(i < str.size() && str[i] != ' ') //不是空格，找单词最后一个字符的位置
        {
            right++;
        }
        ReverseWord(str, left, right-1); //局部翻转
        i = right;
    }
    return str;
}
/**
 * 左旋转字符串
 * 汇编语言中有一种移位指令叫做左移,现在有个简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
 */
class Solution{
public:
    string LeftRotateString(string str, int n) {
        if(n < 1 || str.empty()) return str;
        n = n%str.size(); //防止n过大
        reverse(str.begin(), str.end());
        reverse(str.begin(), str.end()-n);
        reverse(str.end()-n, str.end());
        return str;
        //循环左移n位可以先翻转整个序列，然后反转倒数n个元素，再翻转前面元素
    }
};