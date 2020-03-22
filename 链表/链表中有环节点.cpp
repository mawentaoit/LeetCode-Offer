/**
 * 方法：利用两个快慢指针在链表中跑，如果有环快指针肯定能超越慢指针一圈并且相遇
 * 如果没有循环则fast会走到null位置，有循环不会走到null位置
 */
class SOlution{
public:
    bool hasCycle(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return false;
        ListNode* fast, *slow;
        slow = fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};
//扩展，如果有环，找出入环节点
/**
 * 分析：环只能在链表后部
假设有环，无环部分结点数为n1,有环部分结点数为n2, slow指针速度为 1结点/step，fast指针速度为2
    假设经过t个step后相遇，则有 2t - t = n2(fast比slow多经过的结点，可以按路径长度来看), slow继续行进n1个结点就能到环入口
    在设一指针entry于head, 速度也为 1结点/step， 则当entry行进n1个结点也可以到入口，entry与slow会在入口相遇
例子：
head编号0，如果设置prehead,则prehead编号为0，方便分析
 
              ↓--------------←↑
    0 -> 1 -> 2 -> 3 -> 4 -> 5
slow: 0 → 1 → 2 → 3 → 4
fast: 0 → 2 → 4 → 2 → 4
无环部分路径长度2，有环部分路径长度4
相遇后，fast比slow多走了有环部分的路径长度4，故在距起点长度4的结点4处相遇
slow继续行进路径长度2就能走完整个链表即到入口，在开头设置一指针entry，则也行进路径长度2到入口与slow相遇
*/
class Solution{
public:
    ListNode* detectCycle(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return nullptr;
        ListNode* slow, *fast, *entry;
        slow = fast = entry = head;
        while(fast && fast->next) //如果有环，fast不可能为nullptr,无环时，fast会运行到末尾nullptr,退出循环
        {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) {
                while(slow != entry) {
                    slow = slow->next;
                    entry = entry->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};