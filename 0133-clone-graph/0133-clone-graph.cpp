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
        if(!node)   return nullptr;
        Node* res = new Node(node->val);
        unordered_map<Node*, Node*> visit;
        queue<Node*> qu;

        // cloneNode(node, res);
        Node* clone = new Node(node->val);
        visit[node] = clone;
        qu.push(node);
        while(!qu.empty()){
            Node* tmp = qu.front();
            qu.pop();
            for(auto neighbor: tmp->neighbors){
                if(!visit.count(neighbor)){
                    Node* newNode = new Node(neighbor->val);
                    visit[neighbor] = newNode;
                    visit[tmp]->neighbors.push_back(newNode);
                    qu.push(neighbor);
                }
                else    visit[tmp]->neighbors.push_back(visit[neighbor]);
            }
        }

        return visit[node];
    }
    void cloneGraph(Node* origin, Node* res){
        for(int i=0; i<origin->neighbors.size(); i++){
            
        }
    }
};