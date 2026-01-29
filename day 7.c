struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* temp;

    // Remove nodes from the start of the list
    while (head != NULL && head->val == val) {
        temp = head;
        head = head->next;
        free(temp);
    }

    // Traverse and remove nodes in the middle and end
    struct ListNode* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->val == val) {
            temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }

    return head;
}
