//
//  remove_element.cpp
//
//  Created by omlenka on 06/12/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()){
            return 0;
        }
        int l = 0;
        int r = nums.size()-1;
        
        
        while(l < r){
            while(r >= 0 && nums[r] == val){
                r--;
            }
            if(l >= r)
                break;
            if(nums[l] == val){
                swap(nums[l], nums[r--]);
            }
            l++;
        }
        if(nums[l] == val){
            return l;
        }
        return l+1;
    }
};
