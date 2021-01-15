//
//  shuffle_the_array_lc1470.cpp
//
//  Created by omlenka on 15/01/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int l = 0, r = n;
        vector<int> res;
        while(l < n){
            res.push_back(nums[l++]);
            res.push_back(nums[r++]);
        }
        return res;
    }
};
