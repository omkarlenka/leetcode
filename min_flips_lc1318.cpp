//
//  min_flips_lc1318.cpp
//
//  Created by omlenka on 20/04/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;
        while(a || b || c){
            int _a = a & 1;
            int _b = b & 1;
            int _c = c & 1;
            
            if(_c == 0){
                if(_a == 0){
                    if(_b == 1){
                        res++;
                    }
                }
                else{
                    if(_b == 0){
                        res++;
                    }
                    else{
                        res += 2;
                    }
                }
            }
            else if(_c == 1){
                if(_a == 0){
                    if(_b == 0){
                        res++;
                    }
                }
            }
            
            a = a >> 1;
            b = b >> 1;
            c = c >> 1;
        }
        return res;
    }
};


