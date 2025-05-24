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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupTail = &dummy;
        ListNode* current = head;
        ListNode* prev = nullptr;
        ListNode* nextPtr;
        while(current){
            prev = nullptr;

            // 1. check if we had k nodes
            if(!checkNode(current, k)){
                prevGroupTail->next = current;
                break;
            }
            // 2. reverse k nodes
            int cnt = 0;
            while(cnt < k){
                nextPtr = current->next;
                current->next = prev;
                prev = current;
                current = nextPtr;
                cnt++;
            }

            // 3. connect reverse group 
            prevGroupTail->next->next = current;
            nextPtr = prevGroupTail->next;
            prevGroupTail->next = prev;
            prevGroupTail = nextPtr;
        }
        return dummy.next;
    }
private:
    bool checkNode(ListNode* current, int k){
        while(k && current){
            current = current -> next;
            k--;
        }
        if(k == 0)   return true;
        else    return false;
    }
};
// 1 <- 2  3 -> 4 -> 5
// |
// null

// 2 -> 1 -> 3 -> 4 -> 5