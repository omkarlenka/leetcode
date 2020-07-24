//
//  compare_version_numbers.cpp
//
//
//  Created by omlenka on 24/07/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Solution {
    char* convert(string s)
    {
        char *s1 = new char[s.length()+1];
        int i;
        for(i = 0;i<s.length();i++)
        {
            s1[i] = s[i];
        }
        s1[i] = '\0';
        return s1;
    }
public:
    int compareVersion(string version1, string version2)
    {
        
        char* v1 = convert(version1);
        char* v2 = convert(version2);
        char* token1 = strtok_r(v1,".", &v1);
        char* token2 = strtok_r(v2,".", &v2);
        int val1 = atoi(token1),val2 = atoi(token2);
        int res = 0;
        
        while(true)
        {
            if(val1 > val2)
            {
                res = 1;
                break;
            }
            else if(val1 < val2)
            {
                res = -1;
                break;
            }
            
            if(token1)
            {
                token1 = strtok_r(NULL, ".", &v1);
                if(token1)
                    val1 = atoi(token1);
                else
                    val1 = 0;
            }
            else
                val1 = 0;
            
            if(token2)
            {
                token2 = strtok_r(NULL, ".", &v2);
                if(token2)
                    val2 = atoi(token2);
                else
                    val2 = 0;
            }
            else
                val2 = 0;
            
            if(!token1 && !token2)
                break;
        }
        return res;
    }
};

int main()
{
    Solution S;
    cout << S.compareVersion("1.0", "1.0.0") << endl;
    return 0;
}
