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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        while(head){
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }

    int findLength(ListNode* head){
        int count = 0;
        while(head){
            count++;
            head = head->next;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        

        int length = findLength(head); 
        if (length==0) return NULL;
        k = k%length;
        if (k==0) return head;
        

        ListNode* l1 = reverse(head);
        ListNode* temp = l1;
        while(k>1){
            k--;
            temp = temp->next;
        }
        ListNode* rightHalf = temp->next;
        temp->next  = nullptr;
        ListNode* leftHalf = reverse(l1);
        l1->next = reverse(rightHalf);
        return leftHalf; 

    }
};