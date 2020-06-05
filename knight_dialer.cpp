//
//  knight_dialer.cpp
//
//  Created by omlenka on 06/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
#define MAX 1000000007
    int knightDialer(int N)
    {
        vector<int> old(10,1);
        
        vector<vector<int>> V(10);
        V[0].push_back(4);
        V[0].push_back(6);
        V[1].push_back(6);
        V[1].push_back(8);
        V[2].push_back(7);
        V[2].push_back(9);
        V[3].push_back(4);
        V[3].push_back(8);
        V[4].push_back(3);
        V[4].push_back(9);
        V[4].push_back(0);
        V[5].push_back(0);
        V[6].push_back(1);
        V[6].push_back(7);
        V[6].push_back(0);
        V[7].push_back(2);
        V[7].push_back(6);
        V[8].push_back(1);
        V[8].push_back(3);
        V[9].push_back(2);
        V[9].push_back(4);
        
        for(int i = 2;i<=N;i++)
        {
            vector<int> newv(10,0);
            
            for(int i = 0;i<10;i++)
            {
                if(i == 5)
                    continue;
                
                vector<int> v = V[i];
                
                for(int j:v)
                {
                    newv[j] = (newv[j])% MAX + (old[i]) % MAX;
                    newv[j] %= MAX;
                }
            }
            old.assign(newv.begin(), newv.end());
        }
        
        int sum = 0;
        for(int p: old)
        {
            sum = (sum% MAX)  + (p%MAX);
            sum %= MAX;
        }
        return sum;
    }
};
