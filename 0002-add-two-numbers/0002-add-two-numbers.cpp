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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* num1 = l1;
        ListNode* num2 = l2;

        ListNode* ans = new ListNode(-1);
        ListNode* newHead = ans;
        int carry = 0;
        while(num1 && num2){
            int sum = num1->val+num2->val+carry;
            carry = sum/10;

            ListNode* temp = new ListNode(sum%10);
            ans->next = temp;
            ans = ans->next;
            num1 = num1->next;
            num2 = num2->next;
        }

        while(num1){
            int sum = num1->val+carry;
            carry = sum/10;

            ListNode* temp = new ListNode(sum%10);
            ans->next = temp;
            ans = ans->next;
            num1 = num1->next;
        }

        while(num2){
            int sum = num2->val+carry;
            carry = sum/10;

            ListNode* temp = new ListNode(sum%10);
            ans->next = temp;
            ans = ans->next;
            num2 = num2->next;
        }

        if (carry){
            ListNode* temp = new ListNode(1);
            ans->next = temp;
        }
        return newHead->next;
    }
};