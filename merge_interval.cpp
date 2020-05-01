//
//  merge_interval.cpp
//
//  Created by omlenka on 02/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> _merge_intervals(vector<vector<int>>& left, vector<vector<int>>& right)
    {
        vector<vector<int>> res;
        int i = 0, j = 0;
        bool merged  = false;
        while(i < left.size() && j<right.size())
        {
            vector<int> smaller;
            vector<int> larger;
            if(left[i].empty() || right[j].empty())
                break;
            
            if(left[i][0] < right[j][0])
            {
                smaller = left[i];
                larger = right[j];
            }
            else if(left[i][0] > right[j][0])
            {
                smaller = right[j];
                larger = left[i];
            }
            else
            {
                if(left[i][1] < right[j][1])
                {
                    smaller = left[i];
                    larger = right[j];
                }
                else
                {
                    smaller = right[j];
                    larger = left[i];
                }
            }
            if(larger[0] <= smaller[1])  //overlapping
            {
                res.push_back(vector<int> {smaller[0], max(smaller[1],larger[1])});
                i++;
                j++;
                merged = true;
            }
            else
            {
                res.push_back(smaller);
                if(smaller == left[i])
                    i++;
                else
                    j++;
            }
        }
        
        while(i < left.size())
        {
            res.push_back(left[i++]);
        }
        while(j < right.size())
        {
            res.push_back(right[j++]);
        }
        if(merged)
            return merge(res);
        
        return res;
    }
    
    vector<vector<int>> merge_intervals(vector<vector<int>>& intervals, int s, int e)
    {
        vector<vector<int>> res;
        if(s > e)
            return res;
        if(s == e)
        {
            res.push_back(intervals[s]);
            return res;
        }
        
        int m = (s+e)/2;
        
        vector<vector<int>> res_left = merge_intervals(intervals, s, m);
        vector<vector<int>> res_right = merge_intervals(intervals, m+1, e);
        
        return _merge_intervals(res_left, res_right);
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        return merge_intervals(intervals, 0, int(intervals.size())-1);
    }
};
