/**
 * 请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
 */

class Solution{
public:
    void replaceSpace(char *str, int length) {
        int spacenum = 0;
        for(int i = 0; i < length; i++) {
            if(str[i] == ' ') spacenum++;
        }
        int newLength = length + spacenum*2;
        int indexold = length - 1, indexnew = newLength-1;
        for(; indexold >= 0 && indexnew > indexold; indexold--) {
            if(str[indexold] == ' ') //将空格替换为"20%
            {
                str[indexnew--] = '0';
                str[indexnew--] = '2';
                str[indexnew--] = '%';
            }else {
                str[indexnew--] = str[indexold];
            }
        }
    }
};