class ParkingSystem {
public:
    int bigCount;
    int mediumCount;
    int smallCount;
    ParkingSystem(int big, int medium, int small) {
        bigCount = big;
        mediumCount = medium;
        smallCount = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1){
            if(bigCount == 0) return false;
            bigCount--;
        }else if(carType == 2){
            if(mediumCount == 0) return false;
            mediumCount--;
        }else {
            if(smallCount ==0 ) return false;
            smallCount--;
        }
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */