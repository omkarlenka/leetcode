//
//  pascals_triangle_lc118.cpp
//
//  Created by omlenka on 16/01/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows == 0)
            return res;
        
        res.push_back({1});
        for(int i = 1;i<numRows;i++){
            vector<int> row;
            
            for(int j = 0;j<=i;j++){
                if(j == 0 || j == i){
                    row.push_back(1)   ;
                }
                else{
                    row.push_back(res[i-1][j-1] + res[i-1][j]);
                }
            }
            res.push_back(row);
        }
        return res;
    }
};
