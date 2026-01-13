/**
 * Definition for singly-linked list.
 * struct listNode {
 *     int val;
 *     struct listNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {

    struct ListNode *current= head;
    struct ListNode* prev = NULL;
    struct ListNode* nextnode = NULL;
    
    while(current!=0){
        nextnode=current->next;
        current->next=prev;
          prev = current;             // move prev forward
        current = nextnode; 
    }
    return prev;
}

    