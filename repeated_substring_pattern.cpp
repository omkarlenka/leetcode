//
//  repeated_substring_pattern.cpp
//
//  Created by omlenka on 16/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s)
    {
        return (s+s).substr(1,s.length()*2-2).find(s) != string::npos;
    }
};
