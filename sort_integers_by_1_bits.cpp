//
//  sort_integers_by_1_bits.cpp
//
//  Created by omlenka on 09/11/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Comparator{
    int getOnes(const int &a) const{
        int tmp = a;
        int count = 0;
        while(tmp){
            if(tmp & 1){
                count++;
            }
            tmp = tmp >> 1;
        }
        return count;
    }
public:
    bool operator()(const int &a, const int &b) const{
        int ones_a = getOnes(a);
        int ones_b = getOnes(b);
        if(ones_a < ones_b){
            return true;
        }
        else if(ones_a > ones_b){
            return false;
        }
        return (a<b);
    }
};
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),Comparator());
        return arr;
    }
};
