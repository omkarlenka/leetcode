//
//  mock_longest_absolute_file_path.cpp
//
//  Created by omlenka on 15/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int lengthLongestPath(string input)
    {
        int i = 0;
        vector<int> v;
        int max_path = 0;
        while(i < input.length())
        {
            int t = 0;
            if(input[i] == '\n')
            {
                i++;
                continue;
            }
            while(input[i] == '\t')
            {
                i++;
                t++;
            }
            
            bool isFile = false;
            int l = 0;
            while(i < input.length() && input[i] != '\n')
            {
                l++;
                if(input[i] == '.')
                    isFile = true;
                i++;
            }
            if(isFile)
            {
                if(t-1 >= 0)
                    l += v[t-1];
                if(l > max_path)
                    max_path = l;
            }
            else
            {
                if(v.empty() || t >= v.size())
                {
                    int prev = 0;
                    if(!v.empty())
                        prev = v[v.size()-1];
                    v.push_back(prev+l+1);
                }
                else
                {
                    if(t-1>=0)
                        v[t] = v[t-1] + l+1;
                    else
                        v[t] = l+1;
                }
            }
        }
        return max_path;
    }
};
