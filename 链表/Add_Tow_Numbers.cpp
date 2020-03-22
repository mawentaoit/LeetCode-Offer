//加链表表示的两个数。高位在链表后面，低位在前面
class Solution{
public:
    ListNode* addTwoNumber(ListNode* l1, ListNode* l2){
        ListNode preHead(0);
        ListNode* p = &preHead;
        int carry = 0; //进位
        while(l1 || l2 || carry) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum/10; 
            p->next = new ListNode(sum%10);//创建新的结点
            p = p->next;//指向下一个结点
            l1 = l1 ? l1->next : l1; //若为空，则仍为空，若不为空
            l2 = l2? l2->next : l2;
        }
        return preHead.next;//返回首节点指针
    }
};