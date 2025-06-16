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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)   return nullptr;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* current = head;

        int totalNum = 0;
        while(current){
            current = current->next;
            totalNum++;
        }
        k %= totalNum;
        if(k == 0)  return head;
        current = &dummy;
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;
        for(int i=0; i<k; i++){
            fast = fast->next;
        }

        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* next = slow->next;
        slow->next = nullptr;
        fast->next = head;
        return next;
    }
};