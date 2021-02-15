//
//  ugly_number_II_lc264.cpp
//
//  Created by omlenka on 15/02/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> V(n,0);
        V[0] = 1;
        int p2=0,p3=0,p5 = 0;
        
        int i = 1;
        while(i < n){
            V[i] = min(min(V[p2]*2,V[p3]*3),V[p5]*5);
            
            if(V[i] == V[p2]*2){
                p2++;
            }
            if(V[i] == V[p3]*3){
                p3++;
            }
            if(V[i] == V[p5]*5){
                p5++;
            }
            
            i++;
        }
        
        return V[n-1];
        
    }
};
