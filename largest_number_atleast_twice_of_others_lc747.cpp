//
//  largest_number_atleast_twice_of_others_lc747.cpp
//
//  Created by omlenka on 02/03/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest = -1;
        int second_largest = -1;
        int largest_index, second_largest_index;
        
        for(int i = 0;i<nums.size();i++){
            if(nums[i] > largest){
                second_largest = largest;
                second_largest_index = largest_index;
                largest = nums[i];
                largest_index = i;
            }
            else if(nums[i] > second_largest && nums[i] < largest){
                second_largest = nums[i];
                second_largest_index = i;
            }
        }
        if(largest >= (2*second_largest)){
            return largest_index;
        }
        return -1;
    }
};
