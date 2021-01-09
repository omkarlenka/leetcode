//
//  find_the_duplicate_number_lc287.cpp
//
//  Created by omlenka on 09/01/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++){
            int j = i;
            while(nums[i] != i+1){
                if(nums[i] == nums[nums[i]-1]){
                    return nums[i];
                }
                else{
                    swap(nums[i],nums[nums[i]-1]);
                }
            }
            i = j;
        }
        return -1;
    }
};
