//
//  moving_average_from_data_stream.cpp
//
//  Created by omlenka on 30/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class MovingAverage {
    int window;
    double sum;
    vector<int> v;
    int start;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        window = size;
        sum = 0;
        start = 0;
    }
    
    double next(int val)
    {
        v.push_back(val);
        int curr = v.size()-start;
        sum += val;
        if(curr > window)
        {
            sum -= v[start];
            start++;
            curr = window;
        }
        return sum/curr;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
