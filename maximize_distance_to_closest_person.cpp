//
//  maximize_distance_to_closest_person.cpp
//
//  Created by omlenka on 21/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats)
    {
        vector<int> dist(seats.size(), 0);
        int left = -1;
        
        //left to  right
        for(int i = 0;i<seats.size();i++)
        {
            if(seats[i] == 1)
            {
                left = i;
            }
            else
            {
                if(left != -1)
                {
                    int d = i - left;
                    dist[i] = d;
                }
            }
        }
        
        //right to left
        int right = -1;
        int max_d = 0;
        for(int i = seats.size()-1;i>=0;i--)
        {
            if(seats[i]  == 1)
            {
                right = i;
            }
            else
            {
                if(right != -1)
                {
                    int d = right-i;
                    if(dist[i])
                        dist[i] = min(dist[i], d);
                    else
                        dist[i] = d;
                }
                if(dist[i] > max_d)
                    max_d = dist[i];
            }
        }
        
        return max_d;
    }
};
