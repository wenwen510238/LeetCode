/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        queue<Node*> q;
        unordered_map<Node*, Node*> oldNewMapping;
        if(!node)   return nullptr;

        q.push(node);
        Node* clone = new Node(node->val);
        oldNewMapping[node] = clone;
        while(!q.empty()){
            Node* current = q.front();
            q.pop();
            for(auto& nei: current->neighbors){
                if(oldNewMapping.count(nei))  oldNewMapping[current]->neighbors.push_back(oldNewMapping[nei]);
                else{
                    Node* newNode = new Node(nei->val);
                    oldNewMapping[nei] = newNode;
                    oldNewMapping[current]->neighbors.push_back(newNode);
                    q.push(nei);
                }
            }
        }
        return oldNewMapping[node];
    }
};