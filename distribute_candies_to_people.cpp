//
//  main.cpp
//  distribute_candies_to_people
//
//  Created by omlenka on 25/09/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
    inline int nthSum(int a, int n, int d)
    {
        int S = (n*(2*a+(n-1)*d))/2;
        return S;
    }
    inline int getNth(int a, int n, int d)
    {
        int an = a+(n-1)*d;
        return an;
    }
public:
    vector<int> distributeCandies(double C, int n)
    {
        /*
         x*(x+1)/2 <= c
         x = (-1 +(sqrt(8c+1)))/2
         */
        double x = (-1+sqrt(8*C+1))/2;
        int round = x/n;
        vector<int> res(n,0);
        //Total Sum till round-1
        int T = 0;
        //Update res for round-1
        for(int i=0;i<n;i++)
        {
            if(round == 1)
                res[i] = i+1;
            else
                res[i] = nthSum(i+1, round, n);
            T += res[i];
        }
        
        int remaining = C-T;
        int next = getNth(1, round+1, n);
        
        for(int i = 0;i<n;i++)
        {
            if(remaining == 0)
                break;
            
            if(next <= remaining)
            {
                res[i] += next;
                remaining -= next;
                next += 1;
            }
            else
            {
                res[i] += remaining;
                remaining = 0;
            }
        }
        
        return res;
    }
};

int main()
{
    Solution S;
    vector<int> res = S.distributeCandies(80, 4);
    return 0;
}
