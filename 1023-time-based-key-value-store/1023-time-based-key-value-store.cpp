class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> keyMap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyMap[key].push_back(make_pair(value, timestamp));
    }
    
    string get(string key, int timestamp) {
        if(keyMap.find(key) == keyMap.end())    return "";
        auto& valToTime = keyMap[key];
        int l = 0, r = valToTime.size()-1;
        while(l < r){
            int mid = (l + r) / 2;
            if(valToTime[mid].second == timestamp) return valToTime[mid].first;
            if(valToTime[mid].second > timestamp) r = mid - 1;
            else{
                if (l == mid && valToTime[r].second <= timestamp) return valToTime[r].first;
                else if (l == mid && valToTime[r].second > timestamp) return valToTime[l].first;
                else l = mid;
            }
        }
        if(valToTime[l].second <= timestamp) return valToTime[l].first;
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */