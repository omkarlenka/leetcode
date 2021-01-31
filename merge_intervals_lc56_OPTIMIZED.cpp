//
//  merge_intervals_lc56_OPTIMIZED.cpp
//
//  Created by omlenka on 01/03/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Comparator{
public:
    bool operator()(const vector<int> &a, const vector<int> &b){
        if(a[0] < b[0]){
            return true;
        }
        else if(a[0] > b[0]){
            return false;
        }
        return (a[1] < b[1]);
    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end(), Comparator());
        
        res.push_back(intervals[0]);
        for(int i = 1;i<intervals.size();i++){
            auto itr = res.rbegin();
            if(intervals[i][0] >= (*itr)[0] && intervals[i][0] <= (*itr)[1]){
                int start = min((*itr)[0],intervals[i][0]);
                int end = max((*itr)[1],intervals[i][1]);
                res.pop_back();
                res.push_back({start,end});
            }
            else{
                res.push_back({intervals[i][0],intervals[i][1]});
            }
        }
        return res;
    }
};
