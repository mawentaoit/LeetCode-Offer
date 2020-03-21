/**
 * 实现一个最小栈(要求获取最小值用常数时间)
 * 方法一：用两个栈，一个栈存数据，一个栈存各阶段最小数
 */
class MinStack{
private:
    stack<int> s1; //存数据
    stack<int> s2; //存各阶段最小数
public:
    MinStack() {}
    void push(int x) {
        s1.push(x);
        if(s2.empty() || x <= s2.top()) s2.push(x);
    }
    void pop() {
        if(s1.top() == s2.top()) s2.push(x);
        s1.pop();
    }
    int top() {
        return s1.top();
    }
    int getMin() {
        return s2.top(); 
    }
};