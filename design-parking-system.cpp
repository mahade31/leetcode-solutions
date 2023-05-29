//problem: https://leetcode.com/problems/design-parking-system/

class ParkingSystem {
private:
    int cars[4];
public:
    ParkingSystem(int big, int medium, int small) {
        cars[1] = big;
        cars[2] = medium;
        cars[3] = small;
    }
    
    bool addCar(int carType) {
        if (!cars[carType])
            return false;
        --cars[carType];
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
