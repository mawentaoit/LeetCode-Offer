/**
 * 删除链表中的某一个结点（本题不用考虑尾结点）
通用方法（给的是链表头结点）：可以从头结点开始遍历到要删除结点的上一个结点，然后该结点指向要删除结点的下一个结点，删除要删除的结点，不过需花费O（n）
方法2(给的是要删除结点)：对于非尾结点，将下个结点的内容复制到本结点，在删除掉下一个结点即可（O（1）），
        但是对尾结点，则只能从链表头结点开始遍历到尾结点的前一个结点(O(n))
*/
class Solution{
public:
    void deleteNode(ListNode* node) {
        if(node == nullptr) return;
        if(node->next == nullptr) {
            delete node;
            node = nullptr;
            return;
        }
        node->val = node->next->val;
        ListNode* p = node->next;
        node->next = node->next->next;
        delete p;
        p = nullptr;
        return ;
    }
};