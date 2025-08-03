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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* evenNode = head->next;
        ListNode* oddNode;

        bool isOdd = false;
        while(head && head->next){
            
            // 判斷是不是奇數node，奇數node要記錄最後一個node，因為最後要接回偶數node
            isOdd = !isOdd;
            if(isOdd) oddNode = head;

            ListNode* tmp = head->next;
            head->next = head->next->next;
            head = tmp;
        }

        // 如果結束的時候停在奇數node，要更新奇數node最後位置
        if(!isOdd) oddNode = head;
        
        oddNode->next = evenNode;
        return dummy.next;
    }
};