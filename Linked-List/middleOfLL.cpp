 ListNode* getMiddle(ListNode* &head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        if(head->next->next==NULL){
            return head->next;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast !=NULL){
            fast = fast->next;
            if(fast!=NULL){
                fast = fast->next;
            }
            slow = slow->next;
        }
        return slow;
    }
    ListNode* middleNode(ListNode* head) {
        return getMiddle(head);
    }
}

//two pointer technique where fast is going 2 node and slow is going 1 node
// so when fast going to end then slow going to middle and we returning the middle(return slow)