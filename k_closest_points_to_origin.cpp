//
//  k_closest_points_to_origin.cpp
//
//  Created by omlenka on 26/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        vector<vector<int>> res(K);
        map<double, vector<int>> m;
        for(vector<int> v : points)
        {
            int x = v[0];
            int y = v[1];
            double d = sqrt(v[0]*v[0]+v[1]*v[1]);
            m[d] = v;
        }
        
        map<double, vector<int>>::iterator itr = m.begin();
        int i = 0;
        while(K--)
        {
            vector<int> v;
            v = itr->second;
            res[i++] = v;
            itr++;
        }
        return res;
    }
};
