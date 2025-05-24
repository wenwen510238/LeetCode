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

        ListNode* slow = head;
        ListNode* fast = head;
        int total = 0;

        // 1. count total length
        while(fast){
            total++;
            fast = fast->next;
        }
        fast = head;
        k %= total;

        // 2. fast先往前走k+1布(確保slow, fast中間隔k+1個)
        if(k == 0)  return head;
        for(int i=0; i<k; i++){
            fast = fast->next;
        }

        // 3. slow到後面數來第k+1個，fast到最後一個list
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }

        // 4. reconnect list
        ListNode* res = slow->next;
        slow->next = nullptr;
        fast->next = head;
        return res;
    }
};