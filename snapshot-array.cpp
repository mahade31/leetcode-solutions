//problem: https://leetcode.com/problems/snapshot-array/

class SnapshotArray {
private:
    int snap_id;
    vector <map<int, int>> mp;
public:
    SnapshotArray(int length) {
        snap_id = -1;
        mp.resize(length);
        for (int i = 0; i < length; ++i)
            mp[i][0] = 0;
    }
    
    void set(int index, int val) {
        mp[index][snap_id + 1] = val;
    }
    
    int snap() {
        ++snap_id;
        return snap_id;
    }
    
    int get(int index, int snap_id) {
        if (mp[index].count(snap_id))
            return mp[index][snap_id];
        auto it = mp[index].lower_bound(snap_id);
        --it;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
