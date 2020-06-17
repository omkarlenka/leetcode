//
//  mock_next_closest_time.cpp
//
//  Created by omlenka on 21/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    int getNext(vector<int> &v, int n)
    {
        for(int i =0;i<4;i++)
        {
            if(v[i] > n)
                return v[i];
        }
        return -1;
    }
    
    bool isValidMin(int M)
    {
        if(M < 60)
            return true;
        return false;
    }
    
    bool isValidHour(int H)
    {
        if(H < 24)
            return  true;
        return false;
    }
    string arrayToTime(vector<int> &v)
    {
        string time = "";
        for(int i = 0;i<v.size();i++)
        {
            time += to_string(v[i]);
            if(i == 1)
                time += ":";
        }
        return time;
    }
public:
    string nextClosestTime(string time)
    {
        vector<int> v;
        vector<int> V;
        string res;
        for(int i = 0;i<5;i++)
        {
            if(i != 2)
            {
                v.push_back(time[i] - '0');
                V.push_back(time[i] - '0');
            }
        }
        sort(V.begin(), V.end());
        
        //increment last digit of min and check
        int m = getNext(V,v[3]);
        
        if(m!= -1 && isValidMin(v[2]*10 + m))
        {
            v[3] = m;
            res = arrayToTime(v);
            return res;
        }
        int m1 = getNext(V,v[2]);
        if(m1 != -1 && isValidMin(m1*10 + V[0]))
        {
            v[2] = m1;
            v[3] = V[0];
            res = arrayToTime(v);
            return res;
        }
        
        v[2] = V[0];
        v[3] = V[0];
        
        int h = getNext(V,v[1]);
        if(h != -1 && isValidHour(v[0]* 10  + h))
        {
            v[1] = h;
            res = arrayToTime(v);
            return res;
        }
        v[1] = V[0];
        res = arrayToTime(v);
        return res;
    }
};
