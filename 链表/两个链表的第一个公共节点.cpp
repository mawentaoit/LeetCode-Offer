/**
 * 题目描述：
 * 输入两个链表，找出它们的第一个公共结点
 */
class Solution{
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        //求两链表的长度
        int len1 = findListLength(pHead1);
        int len2 = findListLength(pHead2);
        ListNode* plong = pHead1, *pshort = pHead2;
        if(len1 < len2) {
            pshort = pHead1;
            plong = pHead2;
        }
        for(int i = 1; i <= abs(len1-len2); i++) plong = plong->next;
        while(plong != pshort) {
            plong = plong->next;
            pshort = pshort->next;
        }
        return plong;
    }
private:
    int findListLength(ListNode* p) {
        int n = 0;
        while(p != nullptr) {
            p = p->next;
            n++;
        }
        return n;
    }
};
/**
 * 求链表的交点
 */
class Solution{
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        if(p1 == nullptr || p2 == nullptr) return nullptr;
        while(p1 && p2 && p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
            if(p1 == p2) return p1; //p1, p2同时为nullptr或者指向交汇点
            if(p1 == nullptr) p1 = headB; //重定向到另一个链表首节点
            if(p2 == nullptr) p2 = headA;
        }
        return p1;
    }
};