//
//  sliding_window_maximum_lc239_OPTIMIZED.cpp
//
//  Created by omlenka on 21/01/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> Q(k);
        vector<int> res;
        
        for(int i = 0;i<k;i++){
            while(!Q.empty() &&  (nums[i] >= nums[Q.back()])){
                Q.pop_back();
            }
            Q.push_back(i);
        }
        for(int i = k;i < nums.size();i++){
            res.push_back(nums[Q.front()]);
            
            while(!Q.empty() && Q.front() < (i-k+1)){
                Q.pop_front();
            }
            while(!Q.empty() && nums[i] >= nums[Q.back()]){
                Q.pop_back();
            }
            
            Q.push_back(i);
        }
        
        res.push_back(nums[Q.front()]);
        
        return res;
    }
};
