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
        ListNode* temp = head;

        while(temp){
            ListNode* nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (head==NULL || head->next==NULL) return true;

        // divide into two parts reverse one half then compare each node

        ListNode* fast = head->next;
        ListNode* slow = head;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = reverse(slow->next);
        ListNode* temp = newHead;
        fast = head;
        while(newHead){
            if (newHead->val!=fast->val) {
                reverse(temp);
                return false;
            }
            fast = fast->next;
            newHead = newHead->next;
        }

        reverse(temp);
        return true;
    }
};