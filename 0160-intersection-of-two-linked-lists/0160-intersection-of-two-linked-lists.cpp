class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int n1 = 0, n2 = 0;

        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while(t1){
            n1++;
            t1 = t1->next;
        }

        while(t2){
            n2++;
            t2 = t2->next;
        }

        // Reset pointers
        t1 = headA;
        t2 = headB;

        int diff = abs(n1 - n2);

        while(diff--){
            if(n1 > n2)
                t1 = t1->next;
            else
                t2 = t2->next;
        }

        while(t1 && t2){
            if(t1 == t2)
                return t1;

            t1 = t1->next;
            t2 = t2->next;
        }

        return NULL;
    }
};