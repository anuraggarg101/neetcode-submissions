class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> db{};
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        db[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(db.find(key) == db.end()) return "";
        const auto &arr = db[key];
        int l = 0;
        int h = arr.size() - 1;
        
        string ans = "";
        while(l <= h) {
            int mid = (l+h)/2;
            if(arr[mid].first <= timestamp) {
                ans = arr[mid].second;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return ans;
        
    }
};
