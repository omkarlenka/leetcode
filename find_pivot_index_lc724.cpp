//
//  find_pivot_index_lc724.cpp
//
//  Created by omlenka on 22/03/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int n:nums){
            sum += n;
        }
        
        int curr_sum = 0;
        
        for(int i = 0;i<nums.size();i++){
            if(!((sum - nums[i]) & 1)){
                if(curr_sum == (sum-nums[i])/2){
                    return i;
                }
            }
            curr_sum += nums[i];
        }
        return -1;
    }
};
