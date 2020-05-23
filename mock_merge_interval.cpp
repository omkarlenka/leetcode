//
//  mock_merge_interval.cpp
//
//  Created by omlenka on 23/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
    vector<vector<int>> mergeIntervals(vector<vector<int>> &L, vector<vector<int>> &R)
    {
        vector<vector<int>> M;
        
        int i = 0, j = 0;
        int l = L.size(), r = R.size();
        bool merged = false;
        while (i<l && j <r)
        {
            vector<int> smaller;
            vector<int> larger;
            
            
            if(L[i][0] <= R[j][0])
            {
                smaller = L[i];
                larger = R[j];
            }
            else
            {
                smaller = R[j];
                larger = L[i];
            }
            
            if(larger[0] <= smaller[1])
            {
                vector<int> res(2);
                res[0] = smaller[0];
                res[1] = max(smaller[1] , larger[1]);
                M.push_back(res);
                
                i++;
                j++;
                merged = true;
            }
            else if(larger[0])
            {
                M.push_back(smaller);
                if(smaller == L[i])
                    i++;
                else
                    j++;
            }
        }
        while(i < l)
            M.push_back(L[i++]);
        while(j < r)
            M.push_back(R[j++]);
        if(merged == true)
            return _merge(M, 0, M.size()-1);
        else
            return M;
    }
    
    vector<vector<int>> _merge(vector<vector<int>>& intervals, int s, int e)
    {
        vector<vector<int>> res;
        if(s > e)
            return res;
        
        if(s == e)
        {
            res.push_back(intervals[s]);
        }
        else
        {
            int m = s+(e-s)/2;
            vector<vector<int>>  left = _merge(intervals, s, m);
            vector<vector<int>>  right = _merge(intervals, m+1, e);
            
            res = mergeIntervals(left, right);
        }
        return res;
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>> res  = _merge(intervals, 0, intervals.size()-1);
        return res;
    }
};
