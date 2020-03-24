/**
 * 问题：判断是否为回文链表
 * 方法：用快慢指针找到链表中部位置，然后翻转右半链表，判断右边链表与左边链表是否相等
 * O(n)O(1)
 */
class Solution{
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;//异常情况处理，为空结点或者一个结点时
        ListNode* slow = head, *fast = head;
        while(fast && fast->next) { //快慢指针法，让slow指向链表中部位置
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* right = reverseList(slow); //反转右边链表
        ListNode* left = head;
        while(left && right) {
            if(left->val == right->val){
                left = left->next;
                right = right->next;
            }else 
                return false;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* next;
        while(cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};