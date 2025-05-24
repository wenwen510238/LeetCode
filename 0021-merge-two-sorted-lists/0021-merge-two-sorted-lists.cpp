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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* Merge;
        ListNode* MergeCurr;
        if(list1 == NULL)   return list2;
        else if(list2 == NULL)   return list1;
        if(list1->val <= list2->val) {
            Merge = new ListNode(list1->val);
            list1 = list1->next;
        }
        else{
            Merge = new ListNode(list2->val);
            list2 = list2->next;
        }
        MergeCurr = Merge;
        while((list1 != NULL) && (list2 != NULL)){
            if(list1->val <= list2->val ){
                MergeCurr->next = list1;
                list1 = list1->next;
            }
            else{
                MergeCurr->next = list2;
                list2 = list2->next;
            }
            MergeCurr =  MergeCurr->next;
        }
        if(list1 != NULL)    MergeCurr->next = list1;
        if(list2 != NULL)    MergeCurr->next = list2;
        return Merge;
    }
};