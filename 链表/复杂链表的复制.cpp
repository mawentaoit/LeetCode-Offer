class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return head;
        //首先创建链表
        Node* next = head;
        Node* p = head;
        while(p) {
            next = new Node(p->val);
            next->next = p->next;
            p->next = next;
            p = next->next;
        }
        //复制随机数
        p = head;
        while(p) {
            if(p->random != nullptr) {
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }
        //分离
        p = head;
        Node virtualhead(0);
        virtualhead.next = head;
        Node* resHead = &virtualhead;
        while(p) {
            resHead->next = resHead->next->next;
            p->next = p->next->next;
            p = p->next;
            resHead = resHead->next;
        }
        return virtualhead.next;
    }
};