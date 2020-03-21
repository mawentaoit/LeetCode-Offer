//问题：有效括号对判断
class Solution{
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c : s) {
            switch (c)
            {
            case '(':
            case '{':
            case '[':
                st.push(c); break;
            case ')':
                if(st.empty() || st.top() != '(') return false;
                else st.pop();
                break;
            case '}':
                if(st.empty() || st.top() != '{') return false;
                else st.pop();
            case ']':
                if(st.empty() || st.top() != '[') return false;
                else st.pop();
            }
        }
        return st.empty(); //消解完后看栈中是否还有元素，如果还有则为false
    }
};

//方法二
class Solution{
public:
    bool isValid(string s) {
        string left = "([{";
        string right = ")]}";
        stack<char> st;
        for(auto iter : s) {
            if(left.find(iter) != string::npos) {
                st.push(iter);
            }else {
                if(st.empty() || st.top() != left[right.find(iter)]) return false;
            }
        }
        return st.empty();
    }
};