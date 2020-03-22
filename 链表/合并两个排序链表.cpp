class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if (len == 0) return NULL;
        // 分组间隔每次扩大两倍
        int interval = 1;
        while (interval < len) {
            // 根据当前间隔，两两合并，合并后的结果保存在两个链表的第一个
            for (int i = 0; i < len - interval; i += 2 * interval) {
                lists[i]  = mergeTwoLists(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }

        return lists[0];
    }
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode prehead(0);
        ListNode* p = &prehead;
        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val < l2->val) {
                p->next = l1; //下一个节点指向11节点
                l1 = l1->next;
            }else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if(l1 != nullptr) p->next = l1;
        if(l2 != nullptr) p->next = l2;
        return prehead.next;
    }
};


//扩展，链表排序
/**
 * 先用快慢指针法找到链表中部位置，队左右子链表递归处理，进行分割和归并
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* slow = head, *fast = head, *pre = head;
        while(fast != nullptr && fast->next != nullptr) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr; //前半段
        return merge(sortList(head), sortList(slow));
        
    }
    ListNode* merge(ListNode* p1, ListNode* p2) {
        if(p1 == nullptr) return p2;
        if(p2 == nullptr) return p1;
        ListNode prehead(0);
        ListNode* p = &prehead;
        while(p1 != nullptr && p2 != nullptr) {
            if(p1->val < p2->val) {
                p->next = p1;
                p1 = p1->next;
            }else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        if(p1 != nullptr) p->next = p1;
        if(p2 != nullptr) p->next = p2;
        return prehead.next;
    }
};