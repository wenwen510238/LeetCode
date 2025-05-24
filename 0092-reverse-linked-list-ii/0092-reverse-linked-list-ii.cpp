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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        // 1. find the node before left 
        for(int i=1; i<left; i++){
            prev = prev->next;
        }

        // 2. reverse left to right node
        ListNode* current = prev->next;
        ListNode* preservePrev = nullptr, *nextPtr;
        for(int i=0; i<=right-left; i++){
            nextPtr = current->next;
            current->next = preservePrev;
            preservePrev = current;
            current = nextPtr;
        } 

        // 3. reconnect the reverse part to the origin part
        prev->next->next = current;
        prev->next = preservePrev;

        return dummy.next;
    }
};