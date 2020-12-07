//
//  contains_duplicate_III.cpp
//
//  Created by omlenka on 07/12/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> S;
        for(int i = 0;i<nums.size();i++){
            auto itr = S.lower_bound(nums[i]);
            if(itr != S.end() && *itr - nums[i] <= t){
                return true;
            }
            if(itr != S.begin()){
                auto prev_itr = prev(itr,1);
                if(nums[i] - *prev_itr <= t){
                    return true;
                }
            }
            S.insert(nums[i]);
            if(S.size() > k){
                auto it = S.find(nums[i-k]);
                S.erase(it);
            }
        }
        return false;
    }
};
