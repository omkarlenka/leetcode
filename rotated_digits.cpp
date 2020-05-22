//
//  rotated_digits.cpp
//
//  Created by omlenka on 22/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    int rotatedDigits(int N)
    {
        int res = 0;
        
        for(int i = 1;i<=N;i++)
        {
            int x = i;
            //has at least one valid digit and rest can be valid or invalid
            bool valid_present = false;
            while(x > 0)
            {
                int d = x%10;
                x /= 10;
                if(d == 2 || d == 5 || d == 6 || d == 9)
                {
                    valid_present = true;
                }
                else if(d == 0 || d == 1 || d == 8)
                {
                    continue;
                }
                else  //other numbers: 3,4,7
                {
                    valid_present = false;
                    break;
                }
            }
            
            if(valid_present)
                res += 1;
        }
        return res;
    }
};
