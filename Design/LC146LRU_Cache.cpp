class LRUCache {
private:
    int capacity;
    std::list<std::pair<int,int>> cache; // {key, value}
    std::unordered_map<int, std::list<std::pair<int,int>>::iterator> map;

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (map.find(key) == map.end())
            return -1;

        // Move accessed node to front (most recent)
        cache.splice(cache.begin(), cache, map[key]);
        return map[key]->second;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            // Update value and move to front
            map[key]->second = value;
            cache.splice(cache.begin(), cache, map[key]);
            return;
        }

        if (cache.size() == capacity) {
            // Remove least recently used (back)
            int oldKey = cache.back().first;
            cache.pop_back();
            map.erase(oldKey);
        }

        // Insert new entry at front
        cache.emplace_front(key, value);
        map[key] = cache.begin();
    }
};