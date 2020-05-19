//
//  divisor_game.cpp
//
//  Created by omlenka on 19/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool divisorGame(int N)
    {
        vector<bool> v(N+1, false);
        
        for(int i = 2;i<=N;i++)
        {
            int j = 2;
            while(j<=i)
            {
                if(i%j == 0)
                {
                    int x = i/j;
                    if(v[i-x] == false)
                    {
                        v[i] = true;
                        break;
                    }
                }
                j++;
            }
        }
        return v[N];
    }
};
