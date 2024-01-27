struct ListNode* deleteDuplicates(struct ListNode* head) {
    bool seen[201] = {false};
    struct ListNode* cursor = head;


    while (cursor) {
        seen[cursor->val + 100] = true;
        while (cursor->next && seen[cursor->next->val + 100])
            cursor->next = cursor->next->next;

        cursor = cursor->next;
    }

    return head;
}

