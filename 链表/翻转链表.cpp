/**
 * 翻转链表
 */
//迭代法
class Solution{
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* next = head;
        while(cur) {
            next = cur->next;
            cur->next = pre; //变换指向
            pre = cur;
            cur = next;//更新指针
        }
        return pre; //最后pre指向最后一个节点
    }
};
//递归法
class Solution{
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};
//扩展，翻转链表(位置m-n翻转)
//方法：队m-n位置处的链表进行翻转，然后连接m-1位置于n位置，m位置与n+1位置
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || !head->next || m < 0 || n <0 || m >= n) return head;
        ListNode prehead(0);
        prehead.next = head;
        ListNode* cur = &prehead;
        for(int i = 1; i <= m-1; i++) {
            cur = cur->next; //最后cur处在m-1位置
        }
        ListNode* pre = cur;
        ListNode* next;
        cur = cur->next; //让cur处在m位置
        ListNode* prefirst = pre, *first = cur; //保存m-1位置和m位置处的节点
        for(int i = m; i <= n; i++) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }//退出时，pre在n处，cur在n+1处
        prefirst->next = pre; //连接m-1与n位置
        first->next = cur;
        return prehead.next;
    }
};