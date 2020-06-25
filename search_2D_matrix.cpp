//
//  search_2D_matrix.cpp
//
//  Created by omlenka on 25/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if(matrix.empty())
            return false;
        int r = 0, c = 0;
        r = matrix.size();
        if(r)
            c = matrix[0].size();
        if(!c)
            return false;
        
        int s = 0, e = r-1;
        while(s<=e)
        {
            int m = s+(e-s)/2;
            if(binary_search(matrix[m].begin(),matrix[m].end(), target))
                return true;
            if(target < matrix[m][0])
                e = m-1;
            else
                s = m+1;
        }
        return false;
    }
};

