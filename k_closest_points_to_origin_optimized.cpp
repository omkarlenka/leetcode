//
//  k_closest_points_to_origin_optimized.cpp
//
//  Created by omlenka on 26/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

bool comp(const vector<int> &l, const vector<int> &r)
{
    return l[0]*l[0]+l[1]*l[1] < r[0]*r[0]+r[1]*r[1];
}
class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        std::nth_element(points.begin(), points.begin()+K, points.end(), comp);
        points.resize(K);
        return points;
    }
};
