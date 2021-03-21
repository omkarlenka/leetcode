//
//  triangle_lc120.cpp
//
//  Created by omlenka on 21/03/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int res = INT_MAX;
        
        for(int i = 0;i<row;i++){
            int c = triangle[i].size();
            int tmp;
            for(int j = 0;j<c;j++){
                if(j == 0){
                    //update left and right
                    if(i+1 < row){
                        triangle[i+1][j] += triangle[i][j];
                        tmp = triangle[i+1][j+1];
                        triangle[i+1][j+1] += triangle[i][j];
                    }
                }
                else{
                    if(i+1 < row){
                        //left
                        triangle[i+1][j] = min(triangle[i+1][j], tmp + triangle[i][j]);
                        tmp = triangle[i+1][j+1];
                        triangle[i+1][j+1] += triangle[i][j];
                    }
                }
                if(i == row-1){
                    res = min(res, triangle[i][j]);
                }
            }
        }
        return res;
    }
};
