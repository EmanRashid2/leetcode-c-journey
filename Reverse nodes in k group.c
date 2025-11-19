// LeetCode already provides:
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (!head || k == 1) return head;

    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *prev = &dummy;
    struct ListNode *curr = head;

    int count = 0;
    while (curr) {  // Count total nodes
        count++;
        curr = curr->next;
    }

    curr = dummy.next;
    while (count >= k) {
        struct ListNode *tail = curr;
        struct ListNode *nextGroup = curr;
        struct ListNode *prevNode = NULL;

        // Reverse k nodes
        for (int i = 0; i < k; i++) {
            struct ListNode *temp = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr = temp;
        }

        // Connect reversed part with previous and next nodes
        prev->next = prevNode;
        tail->next = curr;

        // Move prev to tail for next iteration
        prev = tail;

        count -= k;
    }

    return dummy.next;
}

