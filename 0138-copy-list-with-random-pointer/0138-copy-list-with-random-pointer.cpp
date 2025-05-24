/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)   return nullptr;
        Node* current = head;
        
        // copy node and set copy node next pointer
        while(current){
            Node* copyNode = new Node(current->val);
            copyNode->next = current->next;
            current->next = copyNode;
            current = current->next->next; 
        }

        //set copy node random pointer
        current = head;
        while(current){
            if(current->random) current->next->random = current->random->next;
            current = current->next->next;
        }

        //seperate two list
        current = head;
        Node* newList = head->next;
        while(current){
            Node* copy = current->next;
            current->next = current->next->next;
            if(copy->next) copy->next = copy->next->next;
            else    copy->next = nullptr;  
            current = current->next;
        }
        return newList;
    }
};