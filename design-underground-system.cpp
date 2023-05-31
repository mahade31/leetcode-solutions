//problem: https://leetcode.com/problems/design-underground-system/

class UndergroundSystem {
private:
    map <int, string> start;
    map <int, int> start_time;
    map <pair<string, string>, int> total_time, count;

public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        start[id] = stationName;
        start_time[id] = t;
    }
    
    void checkOut(int id, string stationName, int t) {
        string start_station = start[id];
        int started_at = start_time[id];
        pair <string, string> p = {start_station, stationName};
        total_time[p] += t - started_at;
        ++count[p];
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair <string, string> p = {startStation, endStation};
        return (1.00 * total_time[p]) / count[p];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
