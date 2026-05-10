class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> hashmap;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        hashmap[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        vector values = hashmap[key];
        int l = 0; int r = values.size()-1;
        string res = "";
        while(r>=l){
            int mid = l+(r-l)/2;
            if(values[mid].second <= timestamp){
                res = values[mid].first;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return res;
    }
};
