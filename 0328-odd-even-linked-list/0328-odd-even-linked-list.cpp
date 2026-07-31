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
        if (head==NULL || head->next==NULL) return head;
        ListNode* odd = new ListNode(-1);
        ListNode* oddHead = odd;
        ListNode* even = new ListNode(-1);
        ListNode* evenHead = even;

        ListNode* mover = head;
        int idx = 1;
        while(mover!=NULL){
            if (idx&1){
                odd->next = mover;
                odd = mover;
            }else{
                even->next = mover;
                even = mover;
            }
            mover = mover->next;
            idx++;
        }
        even->next=NULL;
        odd->next=NULL;

        if (oddHead->next==NULL) return evenHead->next;
        if (evenHead->next==NULL) return oddHead->next;

        odd->next = evenHead->next;
        return oddHead->next;
    }
};