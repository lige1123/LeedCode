/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int num = 0;
        ListNode *head = NULL;
        while ( !s1.empty() || !s2.empty() || num > 0) {
            int a = (s1.empty()) ? 0 : s1.top();
            int b = (s2.empty()) ? 0 : s2.top();
            if (!s1.empty()) s1.pop();
            if (!s2.empty()) s2.pop();
            int arr = a + b + num;
            auto CurNode= new ListNode(arr % 10);
            CurNode->next = head;
            head = CurNode;
            num = arr / 10;
        }
        return head;
    }
};
