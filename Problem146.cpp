class LRUCache {
    list<int> keysInOrder;
    unordered_map<int, int> data;
    unordered_map<int, list<int>::iterator> keyPosition;
    int capacity;
    
    pair<unordered_map<int, int>::iterator, bool> fetch(int key) {
        auto it = data.find(key);
        return {it, it != data.end()};
    }
    
    void remove(int key) {
        const auto it = keyPosition[key];
        keysInOrder.erase(it);
        data.erase(key);
        keyPosition.erase(key);
    }
    
    void addToEnd(int key, int value) {
        data[key] = value;
        auto insertedPosition = keysInOrder.emplace_back(key);
        keyPosition[key] = prev(keysInOrder.end());
    }
    
    void update(int key, int value) {
        remove(key);
        addToEnd(key, value);
    }
    
    void insert(int key, int value) {
        if ((int) data.size() < capacity)
            addToEnd(key, value);
        else {
            remove(*keysInOrder.begin());
            addToEnd(key, value);
        }
    }
public:
    LRUCache(int capacity): keysInOrder({}), data({}), keyPosition({}), capacity(capacity) {
    }
    
    int get(int key) {
        auto [it, found] = fetch(key);
        if (!found)
            return -1;
        else {
            auto valueToReturn = it -> second;
            update(key, valueToReturn);
            return valueToReturn;
        }
    }
    
    void put(int key, int value) {
        auto [existingPosition, found] = fetch(key);
        if (found)
            update(key, value);
        else
            insert(key, value);
    }
};
