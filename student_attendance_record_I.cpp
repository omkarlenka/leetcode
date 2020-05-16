//
//  student_attendance_record_I.cpp
//
//  Created by omlenka on 16/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool checkRecord(string s)
    {
        bool res = true;
        int A = 0;
        int cont_L = 0;
        
        for(char c: s)
        {
            if(c == 'A')
                A++;
            
            if(c == 'L')
                cont_L++;
            else
                cont_L = 0;
            
            if(A > 1 || cont_L == 3)
            {
                res = false;
                break;
            }
        }
        
        return res;
    }
};
