//
//  maximal_square_lc221.cpp
//
//  Created by omlenka on 05/02/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    // void printMatrix(vector<vector<int>> &M, int m, int n){
    //     for(vector<int> v : M){
    //         for(int n:v){
    //             cout << n << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << "---------------------" << endl;
    // }
    
public:
    int maximalSquare(vector<vector<char>>& M) {
        int res = 0;;
        int m = M.size();
        int n = M[0].size();
        vector<vector<int>> matrix(m,vector<int>(n,0));
        vector<vector<int>> vertical(m,vector<int>(n,0));
        vector<vector<int>> horizontal(m,vector<int>(n,0));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                matrix[i][j] = M[i][j]-'0';
                if(matrix[i][j] == 1){
                    vertical[i][j] = 1;
                    horizontal[i][j] = 1;
                    if(i-1 >= 0){
                        vertical[i][j] = vertical[i-1][j]+1;
                    }
                    if(j-1 >= 0){
                        horizontal[i][j] = horizontal[i][j-1]+1;
                    }
                }
                
            }
        }
        // printMatrix(matrix, m, n);
        // printMatrix(vertical, m, n);
        // printMatrix(horizontal, m, n);
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j] == 1){
                    if(i-1 >= 0 && j-1 >=0){
                        if(matrix[i-1][j-1] > 0){
                            int v = 0, h = 0;
                            v = vertical[i-1][j];
                            h = horizontal[i][j-1];
                            matrix[i][j] = min(min(v, h),matrix[i-1][j-1])+1;
                        }
                    }
                }
                if(matrix[i][j] > res){
                    res = matrix[i][j];
                }
            }
        }
        return res*res;
    }
};

int main() {
    Solution S;
    vector<vector<char>> v = {{'1','0','1','1','1'},{'1','1','1','1','0'},{'0','1','1','1','1'},{'1','1','0','1','1'}};
    
    cout << S.maximalSquare(v) << endl;
    
    return 0;
}
