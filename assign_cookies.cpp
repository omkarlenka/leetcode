//
//  assign_cookies.cpp
//
//  Created by omlenka on 12/09/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int res = 0;
        vector<int>::iterator low = s.begin();
        for(int i = 0;i<g.size();i++)
        {
            if(low == s.end())
                break;
            low = lower_bound(low,s.end(),g[i]);
            if(low == s.end())
                break;
            else
                res++;
            low = next(low, 1);
        }
        return res;
    }
};

int main()
{
    Solution S;
    vector<int> g = {1,2,1,1};
    vector<int> s = {1,2,3};
    cout << S.findContentChildren(g, s) << endl;
    return 0;
}
