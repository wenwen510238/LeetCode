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
        if(!head)   return nullptr;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevTail = &dummy;
        while(prevTail->next && prevTail->next->next){
            if(prevTail->next->val == prevTail->next->next->val){
                int val = prevTail->next->val;
                while(prevTail->next && prevTail->next->val == val){
                    prevTail->next = prevTail->next->next;
                }
            }
            else{
                prevTail = prevTail->next;
            }
        }
        return dummy.next;
    }
};