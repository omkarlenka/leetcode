//
//  find_all_duplicates_lc442.cpp
//
//  Created by omlenka on 22/04/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int i = 0;
        vector<int> res;
        while(i < nums.size()){
            if(nums[i] == nums[nums[i]-1]){
                i++;
            }
            else{
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        
        for(int i = 0;i<nums.size();i++){
            if(nums[i] != i+1){
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};
