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
    unordered_map<Node*, Node*> oldNewMapping;
    Node* cloneGraph(Node* node) {
        
        if(!node)   return nullptr;
        if(oldNewMapping.count(node))   return oldNewMapping[node];
        Node* clone = new Node(node->val);
        oldNewMapping[node] = clone;
        for(auto& nei: node->neighbors){
            clone->neighbors.push_back(cloneGraph(nei));
        }
        return clone;
    }
};