/**
 * 问题：在链表中，将所有奇数序号的结点放到前面，偶数序号的结点放在后面，要求就地解决
 * 与问题"调整数组中奇数偶数顺序"区别在于前者调整结点，而后者调整的是值
 * O(n), O(1)
 */
class Solution{
public:
    ListNode* oddEventList(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* odd = head;
        ListNode* evenhead = head->next, *even = evenhead; //偶数序列结点指针与头指针
        while(even && even->next) {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenhead;//连接奇数序列链表和偶数序列链表
        return head;
    }
};

