/**
 * 问题：用队列实现栈
 * 方法一：用两个队列
 * 插入 q1借助辅助队q2在队首插入元素
 * 删除 q1队首元素出队
 * 访问 访问q1队首元素
 * 判断 判断q1是否为空
 */
class MyStack{
private:
queue<int> q1, q2;
public:
    MyStack(){

    }
    void push(int x) {
        while(!q1.empty()) //q1转移到q2{
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop() {
        int top_element = q1.front();
        q1.pop();
        return top_element;
    }
    int top() {
        return q1.front();
    }
    bool empty() {
        return q1.empty();
    }
};