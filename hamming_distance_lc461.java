//
//  rhamming_distance_lc461.java
//
//  Created by omlenka on 03/05/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

class Solution {
    public int hammingDistance(int x, int y) {
        int X = x^y;
        int res = 0;
        while(X != 0){
            if((X & 1) == 1){
                res++;
            }
            X = X >> 1;
        }
        return res;
    }
}