class RandomizedSet {
public:
    vector<int> numSet;
    unordered_map<int, int> map; //val, index
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(map.find(val) != map.end())  return false;
        numSet.push_back(val);
        map[val] = numSet.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(map.find(val) == map.end())  return false;
        auto it = map.find(val);
        numSet[it->second] = numSet.back();
        numSet.pop_back();
        map[numSet[it->second]] = it->second;
        map.erase(val);
        return true;
    }
    
    int getRandom() {
        return numSet[rand()%numSet.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */