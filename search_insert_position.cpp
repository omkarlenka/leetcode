//
//  search_insert_position.cpp
//
//  Created by omlenka on 18/11/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int searchInsertUtil(vector<int>& nums, int start, int end, int target){
        int mid = start+ (end-start)/2;
        
        if(target == nums[mid]){
            return mid;
        }
        else if(target > nums[mid]){
            if((mid + 1 < nums.size() && target < nums[mid+1]) ||
               mid == nums.size()-1)
            {
                return mid+1;
            }
            return searchInsertUtil(nums, mid+1, end, target);
        }
        if((mid - 1 >=0 && target > nums[mid-1]) ||
           (mid == 0))
        {
            return mid;
        }
        return searchInsertUtil(nums, start, end-1, target);
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        return searchInsertUtil(nums, 0, nums.size()-1, target);
    }
};
