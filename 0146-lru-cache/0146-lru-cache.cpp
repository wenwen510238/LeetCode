class LRUCache {
public:
    struct Node{
        int val;
        int key;
        Node* next;
        Node* prev;
        Node(int k, int v){
            key = k;
            val = v;
        }
    };

    int cap;
    unordered_map<int, Node*> hash;

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node* newNode){
        newNode->next = head->next;
        newNode->prev = head;

        head->next->prev = newNode;
        head->next = newNode;
    }

    void deleteNode(Node* delNode){
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
    }

    int get(int key) {
        if(hash.find(key) != hash.end()){
            Node* res = hash[key];
            int ans = res->val;

            deleteNode(res);
            addNode(res);

            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {  
        if(hash.find(key) != hash.end()){
            Node* curr = hash[key];
            hash.erase(key);
            deleteNode(curr);
        }
        
        if(hash.size() == cap){
            hash.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        hash[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */