//
//  shuffle_an_array_lc384.cpp
//
//  Created by omlenka on 12/01/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class Solution {
    vector<int> orig_nums;
public:
    Solution(vector<int>& nums) {
        srand(time(0));
        orig_nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return orig_nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuffled_nums = orig_nums;
        for(int i = 0;i<shuffled_nums.size();i++){
            int index = rand() % shuffled_nums.size();
            swap(shuffled_nums[i], shuffled_nums[index]);
        }
        return shuffled_nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
