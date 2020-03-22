//输入一个链表，从尾到头打印链表每个节点的值
//方法：利用栈的后进先出特性
//如果可以改变链表结构，则可以先反转链表指针，再遍历输出即可，可以不用辅助空间
class Solution{
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<ListNode*> nodes;
        ListNode* p = head;
        while(p != nullptr) {
            nodes.push(p);
            p = p->next;
        }
        vector<int> res;
        while(!nodes.empty()) {
            p = nodes.top();
            res.push_back(p->val);
            nodes.pop();
        }
        return res;
    }
};
//改变链表结构法
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        /*
        vector<int> res;
        if(head == nullptr) return res;
        stack<int> st;
        while(head != nullptr) {
            st.push(head->val);
            head = head->next;
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
        */
        vector<int> res;
        if(head == nullptr) return res;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* after;
        while(cur != nullptr) {
            after = cur->next;
            cur->next = pre;
            pre = cur;
            cur = after;
        }
        while(pre != nullptr) {
            res.push_back(pre->val);
            pre = pre->next;
        }
        return res;
    }
};