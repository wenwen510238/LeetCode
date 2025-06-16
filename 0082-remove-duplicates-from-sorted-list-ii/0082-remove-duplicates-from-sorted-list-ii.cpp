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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)  return nullptr;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* current = &dummy;
        while(current->next && current->next->next){
            if(current->next->val == current->next->next->val){
                int val = current->next->val;
                while(current->next && current->next->val == val){
                    current->next = current->next->next;
                }
            }
            else current = current->next;
        }
        return dummy.next;

    }
};