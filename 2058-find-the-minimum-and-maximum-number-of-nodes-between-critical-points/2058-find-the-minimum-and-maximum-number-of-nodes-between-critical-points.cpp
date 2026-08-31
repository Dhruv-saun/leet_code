/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1;
        int last = -1;
        int minDist = INT_MAX;
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;
        int pos = 1;
        while (next != nullptr) {
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {
                if (first == -1) {
                    first = pos;
                } else {
                    minDist = min(minDist, pos - last);
                }
                last = pos;
            }
            prev = curr;
            curr = next;
            next = next->next;
            pos++;
        }
        if (first == last)
            return {-1, -1};
        int maxDist = last - first;
        return {minDist, maxDist};
    }
};