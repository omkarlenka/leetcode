//
//  sqrt_lc69.cpp
//
//  Created by omlenka on 02/01/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
    int sqrtUtil(int s, int e, int x){
        long m = e-(e-s)/2;
        if(m*m == x){
            return m;
        }
        else if(m*m < x){
            if(m+1 < x){
                if((m+1)*(m+1) > x)
                    return m;
                else
                    return sqrtUtil(m+1,e,x);
            }
        }
        
        if(m-1 >= 1){
            if((m-1)*(m-1) < x)
                return m-1;
            else
                return sqrtUtil(s,m-1,x);
        }
        return -1;
    }
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1){
            return x;
        }
        return sqrtUtil(1,x,x);
    }
};
