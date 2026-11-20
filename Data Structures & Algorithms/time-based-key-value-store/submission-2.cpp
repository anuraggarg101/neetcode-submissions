class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> mp{};

    string findLatestValue(const vector<pair<int, string>> &arr, int timestamp) {
        // search for last value with pair.first <= timestamp
        // if found, return value, else return ""
        int l = 0;
        int n = arr.size();
        int r = n-1;

        while(l<r) {
            int mid = l + (r - l + 1)/2;
            if(arr[mid].first > timestamp) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        return arr[l].second;
    }
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = mp.find(key);
        if(it == mp.end()) {
            return "";
        } else {
            const auto &arr = it->second;
            return arr[0].first > timestamp ? "" : findLatestValue(arr, timestamp);
        }
        return "";
    }
};
