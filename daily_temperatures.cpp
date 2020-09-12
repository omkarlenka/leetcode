//
//  daily_temperatures.cpp
//
//  Created by omlenka on 13/09/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T)
    {
        vector<int> res(T.size(),0);
        stack<int> S;
        
        for(int i = 0;i<T.size();i++)
        {
            while(!S.empty())
            {
                int top = S.top();
                if(T[i] > T[top])
                {
                    S.pop();
                    res[top]  = (i-top);
                }
                else
                    break;
                
            }
            S.push(i);
        }
        return res;
    }
};

int main()
{
    Solution S;
    vector<int> T = {73,74,75,71,69,72,76,73};
    vector<int> res = S.dailyTemperatures(T);
    return 0;
}
