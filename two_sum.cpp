//
//  two_sum.cpp
//
//  Created by omlenka on 07/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        multimap<int, int> M;
        vector<int> res(2);
        
        for(int i = 0;i < nums.size();i++)
        {
            multimap<int, int>::iterator itr;
            itr = M.find(target - nums[i]);
            if(itr != M.end())
            {
                res[0] = itr->second;
                res[1] = i;
                break;
            }
            M.insert(pair<int, int> (nums[i], i));
        }
        return res;
    }
};
