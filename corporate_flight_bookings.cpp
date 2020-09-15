//
//  corporate_flight_bookings.cpp
//
//  Created by omlenka on 15/09/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n)
    {
        vector<int> res(n+1,0);
        for(vector<int> v: bookings)
        {
            res[v[0]-1] += v[2];
            res[v[1]] -= v[2];
        }
        
        for(int i = 1;i<n+1;i++)
        {
            res[i] += res[i-1];
        }
        res.pop_back();
        return res;
    }
};
