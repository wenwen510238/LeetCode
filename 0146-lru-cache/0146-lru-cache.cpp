class LRUCache {
public:
    list<pair<int, int>> node;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end())  return -1;
        auto iter = cache[key];
        int val = iter->second;
        node.erase(iter);
        node.push_front({key, val});
        cache[key] = node.begin();
        return val;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            auto iter = cache[key];
            node.erase(iter);
            node.push_front({key, value});
            cache[key] = node.begin();
        }
        else{
            if(cache.size() == cap){
                int oldKey = node.back().first;
                node.pop_back();
                cache.erase(oldKey);
            }
            node.push_front({key, value});
            cache[key] = node.begin();
        }
    }
private:
    int cap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */