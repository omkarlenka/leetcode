//
//  jewels_and_stones.cpp
//
//  Created by omlenka on 03/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;
class Solution {
public:
    int numJewelsInStones(string J, string S)
    {
        unordered_set<char> us;
        for(char c: J)
        {
            us.insert(c);
        }
        int res = 0;
        for(char c: S)
        {
            if(us.find(c) != us.end())
                res++;
        }
        return res;
    }
};
