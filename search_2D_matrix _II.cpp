//
//  search_2D_matrix_II.cpp
//
//  Created by omlenka on 25/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int r = matrix.size();
        int c = 0;
        if(r)
            c = matrix[0].size();
        else
            return false;
        if(!c)
            return false;
        
        int i = 0, j = c-1;
        while(i<r && j >=0)
        {
            if(target == matrix[i][j])
            {
                return true;
            }
            if(target < matrix[i][j])
                j--;
            else
                i++;
        }
        return false;
    }
};


