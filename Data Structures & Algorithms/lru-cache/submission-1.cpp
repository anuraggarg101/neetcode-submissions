class LRUCache {
private:
    using ListNodeType = std::pair<int, int>; // key, value
    std::list<ListNodeType> entries;
    unordered_map<int, list<ListNodeType>::iterator> lookup;
    int capacity_ = 0;
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
        lookup.reserve(capacity_);
    }
    
    int get(int key) {
        auto it = lookup.find(key);
        if(it == lookup.end()) return -1;

        // reorder entries list with current access node at front
        entries.splice(entries.begin(), entries, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = lookup.find(key);
        
        if(it != lookup.end()) {
            it->second->second = value;
            entries.splice(entries.begin(), entries, it->second);
            return;
        }

        if(lookup.size() == capacity_) {
            int lruKey = entries.back().first;
            lookup.erase(lruKey);
            entries.pop_back();
        }

        entries.emplace_front(key, value);
        lookup[key] = entries.begin();
        return;
        
    }
};
