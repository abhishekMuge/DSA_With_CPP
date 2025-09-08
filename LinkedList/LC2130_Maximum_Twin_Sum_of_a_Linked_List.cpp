class Solution {
public:
    int pairSum(ListNode* head) {
        // Step 1: Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Step 3: Calculate twin sums
        int maxSum = 0;
        ListNode* first = head;
        ListNode* second = prev; // head of reversed second half
        while (second) {
            maxSum = std::max(maxSum, first->val + second->val);
            first = first->next;
            second = second->next;
        }

        return maxSum;
    }
};
