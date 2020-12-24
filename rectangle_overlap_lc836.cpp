//
//  rectangle_overlap_lc836.cpp
//
//  Created by omlenka on 24/12/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    bool isOverlapping(vector<int> &rec1, vector<int> &rec2){
        if(rec1[0] >= rec2[2])
            return false;
        if(rec1[2] <= rec2[0])
            return false;
        if(rec1[1] >= rec2[3])
            return false;
        if(rec1[3] <= rec2[1])
            return false;
        
        return true;
    }
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(rec1 == rec2)
            return true;
        
        if(rec1[0] == rec1[2] || rec1[1] == rec1[3])
            return false;
        if(rec2[0] == rec2[2] || rec2[1] == rec2[3])
            return false;
        
        return isOverlapping(rec1, rec2);
    }
};
