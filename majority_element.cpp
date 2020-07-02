//
//  majority_element.cpp
//
//  Created by omlenka on 02/07/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        unordered_map<int,int> M;
        for(int n:nums)
        {
            M[n]++;
            if(M[n] > floor(nums.size()/2))
                return n;
        }
        return -1;
    }
};
