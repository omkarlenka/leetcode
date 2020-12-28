//
//  design_parking_lot_1603.cpp
//
//  Created by omlenka on 28/12/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

class ParkingSystem {
    int big, medium, small;
    
public:
    ParkingSystem(int big, int medium, int small) {
        this->big = big;
        this->medium = medium;
        this->small = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1){
            if(big){
                big--;
                return true;
            }
        }
        else if(carType == 2){
            if(medium){
                medium--;
                return true;;
            }
        }
        else{
            if(small){
                small--;
                return true;
            }
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
