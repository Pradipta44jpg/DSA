/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode*reverse( struct ListNode* head){
    struct ListNode* prev=NULL;
    struct ListNode* cur;
    cur=head;
    struct ListNode* next =NULL;
    while(cur !=NULL){
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
       
    }
   return prev;
 }
 bool compare(struct ListNode* h1, struct ListNode* h2) {
    while (h1 != NULL && h2 != NULL) {
        if (h1->val != h2->val)
            return false;
        h1 = h1->next;
        h2 = h2->next;
    }
    return true;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return true;

    struct ListNode* rev = reverse(head);
    bool ans = compare(head, rev);
    reverse(rev);   // restore original list

    return ans;
}
