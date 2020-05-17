//
//  long_pressed_name.cpp
//
//  Created by omlenka on 17/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed)
    {
        if(name == typed)
            return true;
        
        int l1 =  name.length();
        int l2 = typed.length();
        
        if(l2  < l1)
            return false;
        
        int i = 0, j = 0;
        
        while(i < l1 && j < l2)
        {
            if(name[i] == typed[j])
            {
                i++;
                j++;
            }
            else
            {
                if(j-1 >= 0 && typed[j-1] == typed[j])
                    j++;
                else
                    break;
            }
        }
        
        while(j < l2)
        {
            if(j-1 >= 0 && typed[j-1] == typed[j])
                j++;
            else
                break;
        }
        
        if(i == l1 && j == l2)
            return true;
        else
            return false;
    }
};
