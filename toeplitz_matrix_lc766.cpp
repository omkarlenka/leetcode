//
//  toeplitz_matrix_lc766.cpp
//
//  Created by omlenka on 01/05/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int res = true;
        int r = matrix.size();
        int c = matrix[0].size();
        for(int k = 0;k<c;k++){
            int i = 0;
            int j = k;
            int e = matrix[i][j];
            while(i + 1 < r && j + 1 < c){
                if(matrix[i+1][j+1] != e){
                    return false;
                }
                else{
                    i++;
                    j++;
                }
            }
        }
        for(int k = 1;k<r;k++){
            int i = k;
            int j = 0;
            int e = matrix[i][j];
            while(i + 1 < r && j + 1 < c){
                if(matrix[i+1][j+1] != e){
                    return false;
                }
                else{
                    i++;
                    j++;
                }
            }
        }
        return true;
    }
};
