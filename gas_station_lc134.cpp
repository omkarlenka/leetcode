//
//  gas_station_lc134.cpp
//
//  Created by omlenka on 25/01/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int getSum(vector<int> &v){
        int sum = 0;
        for(int n:v){
            sum += n;
        }
        return sum;
    }
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(getSum(gas) < getSum(cost))
            return -1;
        
        int covered = 0;
        int n = gas.size();
        int fuel = 0;
        int i = 0;
        int start = i;
        
        while(covered != n){
            if(fuel + gas[i] >= cost[i]){
                covered++;
                fuel += gas[i]-cost[i];
                if(start == -1)
                    start = i;
            }
            else{
                covered = 0;
                fuel = 0;
                start = -1;
            }
            
            i = (i+1)%n;
        }
        return start;
    }
};

int main() {
    Solution S;
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    
    
    cout << S.canCompleteCircuit(gas, cost) << endl;
    
    return 0;
}
