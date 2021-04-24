//
//  sum_of_unique_elements_lc1748.cpp
//
//  Created by omlenka on 24/04/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res = 0;
        for(int i = 0;i<nums.size();i++){
            bool add = true;
            if(i-1 >= 0){
                if(nums[i] == nums[i-1]){
                    add = false;
                }
            }
            if(i+1 < nums.size()){
                if(nums[i] == nums[i+1]){
                    add = false;
                }
            }
            if(add){
                res += nums[i];
            }
        }
        return res;
    }
};
