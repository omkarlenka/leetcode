//
//  missing_ranges.cpp
//
//  Created by omlenka on 19/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> findMissingRanges(vector<int>& nums, int lower, int upper)
{
    vector<string> res;
    if(lower == upper)
    {
        string range;
        if(nums.empty())
        {
            range = to_string(lower);
            res.push_back(range);
        }
        return res;
    }
    if(nums.empty())
    {
        res.push_back(to_string(lower) + "->" + to_string(upper));
        return res;
    }
    for(int i = 0;i<nums.size();i++)
    {
        if(nums[i] != lower && nums[i] != INT_MIN)
        {
            string lower_range;
            if(lower == nums[i] - 1)
            {
                lower_range = to_string(lower);
            }
            else
            {
                lower_range = to_string(lower) + "->" + to_string(nums[i]-1);
            }
            res.push_back(lower_range);
        }
        if(i == nums.size()-1 && nums[i] != upper && nums[i] != INT_MAX)
        {
            string upper_range;
            if(upper == nums[i]+1)
                upper_range = to_string(upper);
            else
                upper_range = to_string(nums[i]+1) + "->" + to_string(upper);
            
            res.push_back(upper_range);
            continue;
            
        }
        if(nums[i] != INT_MAX)
            lower = nums[i]+1;
        else
            break;
    }
    return res;
}

int main() {
    vector<int> v = {-2147483648,-2147483648,0,2147483647,2147483647};
    vector<string> res = findMissingRanges(v, -2147483648, 2147483647);
    return 0;
}
