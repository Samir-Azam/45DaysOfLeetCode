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
    ListNode* findKth(ListNode* head, int k){
        int count = 1;
        while(head && count<k){
            count++;
            head = head->next;
        }
        return head;
    }

    ListNode* reverse(ListNode* head){
        ListNode* prevNode = NULL;
        while(head){
            ListNode* nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        return prevNode;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        while(temp){
            ListNode* kth = findKth(temp, k);
            if (kth==NULL){
                prevNode->next = temp;
                break;
            }
            ListNode* nextNode = kth->next;
            kth->next = NULL;
            ListNode* newHead = reverse(temp);
            if (temp==head) head = newHead;
            else prevNode->next = newHead;
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};