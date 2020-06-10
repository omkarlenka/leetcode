//
//  trapping_rain_water.cpp
//
//  Created by omlenka on 11/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <stack>
#include <map>
#include <vector>

using namespace std;

class Solution {
    int helper(vector<int> &height, map<int,int> &M)
    {
        map<int,int>::iterator itr;
        int last_filled = -1;
        int res = 0;
        for(itr = M.begin();itr!= M.end();itr++)
        {
            if(height[itr->first] == 0)
                continue;
            
            int start = itr->first;
            int end = itr->second;
            
            if(last_filled >= start)
                continue;
            int h = min(height[start],height[end]);
            for(int i = start+1;i<end;i++)
            {
                res += (h-height[i]);
            }
            last_filled = end-1;
        }
        
        return res;
    }
    
public:
    int trap(vector<int>& height)
    {
        stack<int> S;
        map<int,int> M;
        
        for(int i = 0;i<height.size();i++)
        {
            while(!S.empty() && height[i] >= height[S.top()])
            {
                M[S.top()] = i;
                S.pop();
            }
            if(height[i] > 0)
                S.push(i);
        }
        while(!S.empty())
            S.pop();
        for(int i = height.size()-1;i>=0;i--)
        {
            while(!S.empty() && height[i] >= height[S.top()])
            {
                int t = S.top();
                if(M.find(i) != M.end())
                {
                    t = max(t, M[i]);
                }
                M[i] = t;
                S.pop();
            }
            if(height[i] > 0)
                S.push(i);
        }
        
        int res = helper(height,M);
        return res;
    }
};

int main()
{
    vector<int> v = {6,4,2,0,3,2,0,3,1,4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3};
//    vector<int> v = {5,0,0,3,0,4,0,1};
    Solution S;
    int res = S.trap(v);
    cout << res << endl;
    return 0;
}
