class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* temp = head;
        int cnt = 0;

        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }

        if(cnt == n){
            ListNode* front = head;
            head = head->next;
            delete front;
            return head;
        }

        int cnt2 = 0;
        temp = head;

        while(temp != NULL && temp->next != NULL){
            cnt2++;

            if(cnt2 == cnt - n){

                ListNode* front = temp->next;

                temp->next = front->next;
                front->next = NULL;
                delete front;

                return head;
            }

            temp = temp->next;
        }

        return head;
    }
};