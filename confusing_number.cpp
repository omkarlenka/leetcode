//
//  confusing_number.cpp
//
//  Created by omlenka on 16/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool confusingNumber(int N)
    {
        vector<int> v;
        int N_Orig = N;
        if(N == 0)
            v.push_back(0);
        while(N)
        {
            int d = N%10;
            if(d == 0 || d == 1 || d ==6 || d == 8 || d == 9)
                v.push_back(d);
            else
                return false;
            N/= 10;
        }
        int l = 0, r = v.size()-1;
        int n = -1;
        while(l <= r)
        {
            // swap(v[l], v[r]);
            if(v[l] == 6)
                v[l] = 9;
            else if(v[l] == 9)
                v[l] = 6;
            if(l != r)
            {
                if(v[r] == 6)
                    v[r] = 9;
                else if(v[r] == 9)
                    v[r] = 6;
            }
            
            l++;
            r--;
        }
        for(int p : v)
        {
            if(n == -1)
                n = p;
            else
                n = (n*10)+p;
        }
        if(n == N_Orig)
            return false;
        else
            return true;
    }
};
