/**
 * 双指针法，前面的指针比后面的领先n+1步，往前走
 */
class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr || n == 0) return head;
        ListNode prehead(0);
        prehead.next = head; //指向首节点
        ListNode* fast = prehead, *slow = prehead;
        for(int i = 1; i <= n+1; i++) {
            fast = fast->next;
        }
        while(fast != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next; //倒数第n个节点
        slow->next = slow->next->next; //跳过倒数第n个节点
        delete temp;
        return prehead.next;
    }
};