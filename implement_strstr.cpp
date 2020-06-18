//
//  implement_strstr.cpp
//
//  Created by omlenka on 18/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

class Solution {
public:
    int strStr(string haystack, string needle)
    {
        if(needle.empty())
            return 0;
        int cur = 0;
        do
        {
            int i = haystack.find(needle[0],cur);
            if(i == -1)
                break;
            if(haystack.substr(i,needle.length()) == needle)
                return i;
            cur =  i+1;
        }while(cur < haystack.length());
        return -1;
    }
};
