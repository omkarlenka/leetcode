//
//  count_of_smaller_after_self.cpp
//
//  Created by omlenka on 07/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
class Solution {
    vector<pair<int, int>> merge(vector<pair<int, int>>& L, vector<pair<int, int>>& R, vector<int> &res)
    {
        int l = L.size(), i = 0;
        int r = R.size(), j = 0;
        vector<pair<int, int>> M(l+r);
        int p = -1;
        while(i < l && j < r)
        {
            if(L[i].first > R[j].first)
            {
                M[++p] = R[j++];
                res[L[i].second]++;
            }
            else
            {
                if(i - 1 >= 0 && L[i].second < L[i-1].second)
                    res[L[i].second] += res[L[i-1].second];
                M[++p] = L[i++];
            }
        }
        if(i < l)
        {
            if(i - 1 >= 0 && L[i].second < L[i-1].second)
                res[L[i].second] += res[L[i-1].second];
            M[++p] = L[i++];
        }
        while(i < l)
        {
            if(L[i].second < L[i-1].second)
                res[L[i].second] += res[L[i-1].second];
            M[++p] = L[i++];
        }
        while(j < r)
        {
            M[++p] = R[j++];
        }
        return M;
    }
    
    vector<pair<int, int>> _countSmaller(vector<pair<int, int>>& v, int s, int e, vector<int> &res)
    {
        vector<pair<int, int>> res_merged;
        if(s > e)
            return res_merged;
        if(s == e)
        {
            res_merged.push_back(v[s]);
            return res_merged;
        }
        int m = (s+e)/2;
        
        vector<pair<int, int>> left = _countSmaller(v, s, m, res);
        vector<pair<int, int>> right = _countSmaller(v, m+1, e, res);
        
        res_merged = merge(left, right, res);
        return res_merged;
    }
    
public:
    vector<int> countSmaller(vector<int>& nums)
    {
        vector<pair<int, int>> v(nums.size());
        for(int i = 0;i<nums.size();i++)
        {
            v[i] = make_pair(nums[i],i);
        }
        vector<int> res(nums.size(), 0);
        
        _countSmaller(v, 0, v.size()-1, res);
        return res;
    }
};
