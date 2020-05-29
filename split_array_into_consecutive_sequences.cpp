//
//  split_array_into_consecutive_sequences.cpp
//
//  Created by omlenka on 29/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

/*
 -  If new number is prev+1:
 -    Whenever the count increases for any number, it is definitely start of new sequence.
 -     If count is same, there is no scope for starting new sequence, add this number to previous sequences
 -   If count is less than count of previous number, close all sequences of length >= 3 and add it to only sequences with length < 3.  If there is no such sequence, add it to length >=3
 - else
 start new sequence
 
 
 */

class Solution {
public:
    bool isPossible(vector<int>& nums)
    {
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
        
        
        
        for(int p = 0;p<seq.size();p++)
        {
            if(seq[p] < 3)
                return false;
        }
        return true;
        
    }
};



