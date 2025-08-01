class LRUCache {
public:
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> mp; //key - list_idx
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.count(key)){
            int val = mp[key]->second;
            cache.erase(mp[key]);
            cache.push_front({key, val});
            mp[key] = cache.begin();
            return val;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            cache.erase(mp[key]);
        }
        else if(cache.size() == cap){
            auto [k, _] = cache.back();
            mp.erase(k);
            cache.pop_back();
        }
        cache.push_front({key, value});
        mp[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */