//
//  swap_adjacent_in_lr_string.cpp
//
//  Created by omlenka on 15/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool canTransform(string start, string end)
    {
        int l1 = start.length();
        int l2 = end.length();
        
        if(l1 !=  l2)
            return false;
        
        int i = 0;
        int XL = 0, RX = 0;
        
        while(i < l1)
        {
            if(XL)
            {
                if(start[i] == 'L')
                {
                    if(end[i] == 'X')
                        XL--;
                    else if(end[i] != 'L')
                        break;
                }
                else if(start[i] == 'X')
                {
                    if(end[i] == 'L')
                        XL++;
                    else if(end[i] != 'X')
                        break;
                }
                else
                    break;
            }
            else if(RX)
            {
                if(start[i] == 'X')
                {
                    if(end[i] == 'R')
                        RX--;
                    else if(end[i] != 'X')
                        break;
                }
                else if(start[i] == 'R')
                {
                    if(end[i] == 'X')
                        RX++;
                    else if(end[i] != 'R')
                        break;
                }
                else
                    break;
            }
            else if(start[i] == 'X' && end[i]  == 'L')
            {
                XL = true;
            }
            else if(start[i] == 'R' && end[i]  == 'X')
            {
                RX = true;
            }
            else if(start[i] != end[i])
                return false;
            
            i++;
        }
        
        if(!RX && !XL)
            return true;
        else
            return false;
    }
};
