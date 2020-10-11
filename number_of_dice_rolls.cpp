//
//  number_of_dice_rolls.cpp
//
//  Created by omlenka on 11/10/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numRollsToTarget(int d, int f, int target)
    {
        vector<int> dp(target+1,0);
        for(int i = 1;i<=min(f,target);i++)
            dp[i] = 1;
        
        for(int i = 2;i<=d;i++)
        {
            vector<int> next_dp(target+1,0);
            for(int j = 1;j<=target;j++)
            {
                for(int k = 1;k<j;k++)
                {
                    if(j-k <= f)
                    {
                        next_dp[j] +=  dp[k];
                    }
                }
            }
            dp = next_dp;
        }
        return dp[target];
    }
};

int main()
{
    Solution S;
    cout << S.numRollsToTarget(1, 6, 3);
    return 0;
}
