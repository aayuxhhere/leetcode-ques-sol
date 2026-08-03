/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp = head;
        vector<int> even;
        vector<int> odd;
        int cnt = 0;
        while(temp!=NULL){
            cnt++;
            if(cnt%2 == 0){
                even.push_back(temp->val);
            }
            else{
                odd.push_back(temp->val);
            }
            temp = temp->next;
        }
        int i = 0;
        temp = head;
        while(i<odd.size()){
            temp->val = odd[i++];
            temp = temp->next;
        }
        i = 0;
        while(i<even.size()){
            temp->val = even[i++];
            temp = temp->next;
        }
        return head;
    }
};