//
//  jump_game.cpp
//
//  Created by omlenka on 18/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& v)
    {
        int n = v.size();
        if(n == 1)
            return true;
        int exp = 1;
        for(int i = n-2;i>0;i--)
        {
            if(v[i] < exp)
                exp++;
            else
                exp = 1;
        }
        
        if(v[0] >= exp)
            return true;
        else
            return false;
    }
};
