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
    
    void insertTohead(Node* newNode){
        newNode->next = head->next;
        newNode->prev = head;

        head->next->prev = newNode;
        head->next = newNode;
    }

    void deleteNode(Node* delNode){
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
        delete delNode;
    }

    void moveTohead(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        insertTohead(node);
    }

    int get(int key) {
        if(hash.find(key) != hash.end()){
            Node* res = hash[key];
            int ans = res->val;

            moveTohead(res);

            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {  
        if(hash.find(key) != hash.end()){
            hash[key]->val = value;
            moveTohead(hash[key]);
        }
        else{
            if(hash.size() == cap){
                hash.erase(tail->prev->key);
                deleteNode(tail->prev);
            }
            insertTohead(new Node(key, value));
            hash[key] = head->next;
        }   
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */