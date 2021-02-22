//
//  minimum_size_subarray_sum_lc209.cpp
//
//  Created by omlenka on 22/02/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;
        int res = INT_MAX;
        int sum = nums[0];
        
        while(l <= r && r<nums.size()){
            if(sum == target){
                if(r-l+1 < res){
                    res = r-l+1;
                }
                
                r++;
                if(r < nums.size()){
                    sum += nums[r];
                }
            }
            else if(sum < target){
                r++;
                if(r < nums.size()){
                    sum += nums[r];
                }
            }
            else{ //sum > target
                if(r-l+1 < res){
                    res = r-l+1;
                }
                sum -= nums[l];
                l++;
            }
            if(res == 1)
                break;
        }
        if(res == INT_MAX)
            res = 0;
        return res;
    }
};
