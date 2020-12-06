//
//  max_number_of_events.cpp
//
//  Created by omlenka on 06/12/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Comparator{
public:
    bool operator()(const vector<int> &a, const vector<int> &b){
        if(a[1] < b[1]){
            return true;
        }
        if(a[1] == b[1]){
            return a[0] < b[0];
        }
        return false;
    }
};
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), Comparator());
        set<int> days;
        int total_days = -1;
        int count = 0;
        for(const auto &event:events){
            total_days = max(total_days, event[1]);
        }
        for(int i = 1;i<= total_days;i++){
            days.insert(i);
        }
        
        for(const auto &event:events){
            int start = event[0], end = event[1];
            auto itr = days.lower_bound(start);
            if(itr != days.end() && *itr <= end){
                count++;
                days.erase(itr);
            }
        }
        return count;
    }
};

int main() {
    Solution S;
    vector<vector<int>> events = {{1,2},{2,3},{3,4},{1,2}};
    cout << S.maxEvents(events) << endl;
    return 0;
}
