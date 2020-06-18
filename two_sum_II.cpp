//
//  two_sum_II.cpp
//
//  Created by omlenka on 18/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int l = 0, r =  numbers.size()-1;
        
        while(l<r)
        {
            if(numbers[l] + numbers[r] == target)
                break;
            if(numbers[l] + numbers[r] < target)
                l++;
            else
                r--;
        }
        return {l+1,r+1};
    }
};
