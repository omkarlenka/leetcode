//
//  find_all_numbers_disappeared_in_array.cpp
//
//  Created by omlenka on 15/12/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int i = 0;
        while(i < nums.size()){
            while(nums[i] != i+1){
                if(nums[nums[i]-1] == nums[i]){
                    break;
                }
                swap(nums[i], nums[nums[i]-1]);
            }
            i++;
        }
        i = 0;
        while(i < nums.size()){
            if(nums[i] != i+1){
                res.push_back(i+1);
            }
            i++;
        }
        return res;
    }
};
