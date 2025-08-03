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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* reservePrev = &dummy;
        ListNode* prev = nullptr;
        ListNode* next;
        
        while(head){
            if(head->next){
                for(int i=0; i<2; i++){
                    next = head->next;
                    head->next = prev;
                    prev = head;
                    head = next;
                }

                ListNode* tmp = reservePrev->next;
                reservePrev->next->next = head;
                reservePrev->next = prev;
                prev = tmp;
                reservePrev = prev;
            }
            else break;
        }

        return dummy.next;
    }
};