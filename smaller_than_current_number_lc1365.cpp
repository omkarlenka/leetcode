//
//  smaller_than_current_number_lc1365.cpp
//
//  Created by omlenka on 25/03/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        multiset<int> S;
        for(int num:nums){
            S.insert(num);
        }
        
        vector<int> res;
        for(int n:nums){
            auto itr = lower_bound(S.begin(),S.end(), n);
            res.push_back(distance(S.begin(),itr));
        }
        return res;
    }
};
