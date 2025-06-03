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
    unordered_map<Node*, Node*> visit;
    Node* cloneGraph(Node* node) {
        if(!node)   return nullptr;
        if(visit.count(node))   return visit[node];
        Node* clone = new Node(node->val);
        visit[node] = clone;
        for(auto neighbor: node->neighbors){
            clone->neighbors.push_back(cloneGraph(neighbor));
        }
        return clone;
    }
};