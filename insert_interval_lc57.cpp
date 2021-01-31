//
//  insert_interval_lc57.cpp
//
//  Created by omlenka on 31/01/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        
        bool merging = false;
        bool merged  = false;
        vector<int> merged_interval;
        
        for(vector<int> interval:intervals){
            if(!merged && !merging && newInterval[1] < interval[0]){
                res.push_back(newInterval);
                res.push_back(interval);
                merged = true;
                merging = false;
            }
            else if(merged){
                res.push_back(interval);
            }
            else{
                int start = newInterval[0];
                int end = newInterval[1];
                if(!merging){  //look for start overlap
                    if(end < interval[0] || start > interval[1]){
                        res.push_back(interval);
                    }
                    else if(start < interval[0]){
                        if(end >= interval[0] && end <= interval[1]){
                            merged_interval.push_back(start);
                            merged_interval.push_back(max(end, interval[1]));
                            res.push_back(merged_interval);
                            merged = true;
                            merging = false;
                        }
                        else if(end > interval[1]){
                            merged_interval.push_back(start);
                            merging = true;
                        }
                    }
                    else if(start >= interval[0] && start <= interval[1]){
                        merged_interval.push_back(min(start,interval[0]));
                        if(end <= interval[1]){
                            merged_interval.push_back(max(end, interval[1]));
                            res.push_back(merged_interval);
                            merged = true;
                            merging = false;
                        }
                        else if(end > interval[1]){
                            merging = true;
                        }
                    }
                }
                else{  //look for end overlap
                    if(end < interval[0]){
                        merged_interval.push_back(end);
                        res.push_back(merged_interval);
                        res.push_back(interval);
                        merged = true;
                        merging = false;
                    }
                    else if(end >= interval[0] && end <= interval[1]){
                        merged_interval.push_back(max(end, interval[1]));
                        res.push_back(merged_interval);
                        merged = true;
                        merging = false;
                    }
                }
            }
        }
        if(merging){
            merged_interval.push_back(newInterval[1]);
            res.push_back(merged_interval);
            merged = true;
        }
        else if(!merged){
            res.push_back(newInterval);
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<vector<int>> intervals = {{3,7},{10,15}};
    vector<int> newInterval = {8,12};
    vector<vector<int>> res = S.insert(intervals, newInterval);
    return 0;
}
