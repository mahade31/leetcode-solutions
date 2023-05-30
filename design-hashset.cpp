//problem: https://leetcode.com/problems/design-hashset/

class MyHashSet {
private:
    bool hash[1000006];
public:
    MyHashSet() {
        for (int i = 0; i <= 1000000; ++i)
            hash[i] = false;
    }
    
    void add(int key) {
        hash[key] = true;
    }
    
    void remove(int key) {
        hash[key] = false;
    }
    
    bool contains(int key) {
        return hash[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
