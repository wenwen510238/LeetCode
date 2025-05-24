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
       
        ListNode* dump = new ListNode(0);
        ListNode* curr = dump;
        int c = 0;
        while(l1 || l2 || c > 0){
            int add = c;
            if(l1){
                add += l1->val;
                l1 = l1->next;
            }
            if(l2){
                add += l2->val;
                l2 = l2->next;
            }
            curr->next = new ListNode(add % 10);
            c = add / 10;
            curr = curr->next;
        }
        return dump->next;
    }
};