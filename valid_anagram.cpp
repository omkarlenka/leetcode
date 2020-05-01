//
//  valid_anagram.cpp
//
//  Created by omlenka on 01/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t)
    {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return (s == t);
    }
};
