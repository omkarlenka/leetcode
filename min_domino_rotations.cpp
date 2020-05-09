//
//  min_domino_rotations.cpp
//
//  Created by omlenka on 10/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B)
    {
        int a = A[0], b = B[0];
        int count_a = 1, count_b = 0;
        int i = 1;
        while(i < A.size())
        {
            if(A[i] == a && B[i] == b)
            {
                count_a++;
            }
            else if(A[i] == b && B[i] == a)
                count_b++;
            else
                break;
            
            i++;
        }
        
        if(i == A.size())
            return min(count_a, count_b);
        
        int val;
        int rot_a, rot_b;
        if(A[i] == a || B[i] == a)
        {
            val = a;
            if(a == b)
            {
                rot_a = 0;
                rot_b = 0;
            }
            else
            {
                rot_a  = count_b;
                rot_b = count_a;
            }
        }
        else if(A[i] == b || B[i] == b)
        {
            val = b;
            if(a == b)
            {
                rot_a = 0;
                rot_b = 0;
            }
            else
            {
                rot_a = count_a;
                rot_b = count_b;
            }
        }
        else
            return -1;
        
        while(i < A.size())
        {
            if(A[i]  == val && B[i] == val)
            {
                i++;
                continue;
            }
            else if(A[i] == val)
                rot_b++;
            else if(B[i] == val)
                rot_a++;
            else
                return -1;
            i++;
        }
        
        return min(rot_a, rot_b);
    }
};
