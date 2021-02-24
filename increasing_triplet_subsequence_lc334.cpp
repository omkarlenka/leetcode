//
//  increasing_triplet_subsequence_lc334.cpp
//
//  Created by omlenka on 24/02/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int len = nums.size();
        vector<int> min;
        vector<int> max(len);
        int smallest = INT_MAX;
        for(int n:nums){
            if(n < smallest){
                smallest = n;
            }
            min.push_back(smallest);
        }
        int largest = INT_MIN;
        for(int i = nums.size()-1;i>=0;i--){
            if(nums[i] > largest){
                largest = nums[i];
            }
            max[i] = largest;
        }
        bool res =  false;
        for(int i = 0;i<nums.size();i++){
            if(min[i] < nums[i] && max[i] > nums[i]){
                res = true;
                break;
            }
        }
        return res;
    }
};
