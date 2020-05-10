//
//  median_of_data_stream.cpp
//
//  Created by omlenka on 11/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;
class MedianFinder {
    priority_queue<int, vector<int> , greater<int>> min_queue;
    priority_queue<int> max_queue;
    int total;
    double median;
public:
    /** initialize your data structure here. */
    MedianFinder()
    {
        total = 0;
        median = INT_MAX;
    }
    
    void addNum(int num)
    {
        total++;
        if(num <= median)
            max_queue.push(num);
        else if(num > median)
            min_queue.push(num);
        int p = min_queue.size() - max_queue.size();
        int q = max_queue.size() - min_queue.size();
        if(p > 1)
        {
            int t = min_queue.top();
            min_queue.pop();
            max_queue.push(t);
        }
        else if(q > 1)
        {
            int t = max_queue.top();
            max_queue.pop();
            min_queue.push(t);
        }
        
        if(total % 2)
        {
            if(max_queue.size() >  min_queue.size())
                median = max_queue.top();
            else
                median = min_queue.top();
        }
        else
        {
            median = (double(min_queue.top())+double(max_queue.top()))/2;
        }
    }
    
    double findMedian()
    {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
