//
//  two_sum.cpp
//
//  Created by omlenka on 07/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
class PairComparator
{
public:
    bool operator()(const pair<int,  int>  &a,  const pair<int, int> &b)
    {
        return (a.first < b.first);
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<pair<int, int>> v;
        for(int i = 0;i < nums.size();i++)
            v.push_back(make_pair(nums[i], i));
        
        sort(v.begin(), v.end(), PairComparator());
        
        int l = 0, r = nums.size()-1;
        vector<int> res(2);
        
        while(l < r)
        {
            if(v[l].first + v[r].first == target)
            {
                res[0] = v[l].second;
                res[1] = v[r].second;
                
                break;
            }
            else if(v[l].first + v[r].first < target)
                l++;
            else
                r--;
        }
        return res;
    }
};
