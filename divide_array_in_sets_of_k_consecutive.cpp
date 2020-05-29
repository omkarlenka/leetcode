//
//  divide_array_in_sets_of_k_consecutive.cpp
//
//  Created by omlenka on 29/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k)
    {
        sort(nums.begin(),nums.end());
        vector<int> seq;
        int start = -1;
        unordered_map<int,int> M;
        for(int n:nums)
        {
            if(M.find(n) == M.end())
                M[n] = 1;
            else
                M[n]++;
        }
        int i = 0;
        while(i<nums.size())
        {
            if(i == 0 || nums[i] > nums[i-1]+1)
            {
                int count = M[nums[i]];
                for(int c = 0;c<count;c++)
                    seq.push_back(1);  //  start new sequence
                start++;
                i +=  count;
            }
            else
            {
                int count2 = M[nums[i]];
                int count1 = M[nums[i-1]];
                if(count2 == count1)
                {
                    for(int j = start;j<seq.size();j++)
                    {
                        seq[j]++;
                    }
                    
                }
                else if(count2 > count1)
                {
                    for(int j = start;j<seq.size();j++)
                    {
                        seq[j]++;
                    }
                    for(int c = 0;c<count2-count1;c++)
                        seq.push_back(1);
                }
                else
                {
                    int j = seq.size()-1;
                    int t = count2;
                    while(t--)
                    {
                        seq[j]++;
                        j--;
                    }
                    start = j+1;
                }
                i += count2;
            }
        }
        
        if(seq.size() == 1)
            return false;
        int l = nums.size();
        for(int p = 0;p<seq.size();p++)
        {
            if(seq[p] < k)
                return false;
        }
        return true;
        
    }
};
