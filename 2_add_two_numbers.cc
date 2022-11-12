struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret = new ListNode();
        ListNode* temp = ret;
        int carry = 0;
        while (l1 != nullptr && l2 != nullptr) {
            ret->next = new ListNode();
            ret->next->val = (carry + l1->val + l2->val) % 10;
            carry = (carry + l1->val + l2->val) / 10;
            ret = ret->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr) {
            ret->next = new ListNode();
            ret->next->val = (carry + l1->val) % 10;
            carry = (carry + l1->val) / 10;
            ret = ret->next;
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            ret->next = new ListNode();
            ret->next->val = (carry + l2->val) % 10;
            carry = (carry + l2->val) / 10;
            ret = ret->next;
            l2 = l2->next;
        }
        if (carry > 0) {
            ret->next = new ListNode();
            ret->next->val = carry;
        }
        return temp->next;
    }
};
