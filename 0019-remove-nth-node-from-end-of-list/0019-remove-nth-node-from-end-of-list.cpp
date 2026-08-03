class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* fast = head;
        ListNode* slow = head;

        for(int i = 0; i < n; i++)
            fast = fast->next;

        if(fast == NULL){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        return head;
    }
};