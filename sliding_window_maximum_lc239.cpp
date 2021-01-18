//
//  sliding_window_maximum_lc239.cpp
//
//  Created by omlenka on 18/01/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        multiset<int> S(nums.begin(), nums.begin()+k);
        int start = 0;
        while(start <= nums.size()-k){
            auto itr1 = S.rbegin();
            res.push_back(*itr1);
            auto itr2 = S.find(nums[start]);
            S.erase(itr2);
            if(start + k < nums.size())
                S.insert(nums[start+k]);
            start++;
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> res =  S.maxSlidingWindow(nums, 3);
    return 0;
}
