class Solution {
    stack<ListNode*> convertToStack(ListNode* l) {
        stack<ListNode*> s;
        while (l) {
            s.emplace(l);
            l = l -> next;
        }
        return s;
    }
    
    int getTotal(int carry, stack<ListNode*>& s1, stack<ListNode*>& s2) {
        int total = carry;
        if (s1.size()) {
            total += s1.top() -> val;
            s1.pop();
        }
        if (s2.size()) {
            total += s2.top() -> val;
            s2.pop();
        }
        return total;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto s1 = convertToStack(l1), s2 = convertToStack(l2);
        int carry = 0;
        ListNode* ans = nullptr;
        while (carry or !s1.empty() or !s2.empty()) {
            int total = getTotal(carry, s1, s2);
            carry = total / 10;
            ListNode* node = new ListNode(total % 10);
            node -> next = ans;
            ans = node;
        }
        return ans;
    }
};
