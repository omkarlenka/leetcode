//
//  pacific_atlantic_water_flow_lc417.cpp
//
//  Created by omlenka on 27/01/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;



class Solution {
    void printMatrix(vector<vector<int>> &M, int m, int n){
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                cout << M[i][j] << " ";
            }
            cout << endl;
        }
        cout << "---------------------" << endl;
    }
    bool DFS(vector<vector<int>>& matrix, vector<vector<int>> &M, int i, int j, int m, int n){
        
        M[i][j] = 0;  //origin
        
        if(i-1>=0 && matrix[i-1][j] <= matrix[i][j]){
            if(M[i-1][j] == -1){
                if(DFS(matrix,M,i-1,j,m,n)){
                    M[i][j] = 1;
                    return true;
                }
            }
            else if(M[i-1][j] == 1){
                M[i][j] = 1;
                return true;
            }
        }
        
        if(j-1>=0 && matrix[i][j-1] <= matrix[i][j]){
            if(M[i][j-1] == -1){
                if(DFS(matrix,M,i,j-1,m,n)){
                    M[i][j] = 1;
                    return true;
                }
            }
            else if(M[i][j-1] == 1){
                M[i][j] = 1;
                return true;
            }
        }
        
        if(j+1<n && matrix[i][j+1] <= matrix[i][j]){
            if(M[i][j+1] == -1){
                if(DFS(matrix,M,i,j+1,m,n)){
                    M[i][j] = 1;
                    return true;
                }
            }
            else if(M[i][j+1] == 1){
                M[i][j] = 1;
                return true;
            }
        }
        
        if(i+1<m && matrix[i+1][j] <= matrix[i][j]){
            if(M[i+1][j] ==  -1){
                if(DFS(matrix,M,i+1,j,m,n)){
                    M[i][j] = 1;
                    return true;
                }
            }
            else if(M[i+1][j] == 1){
                M[i][j] = 1;
                return true;
            }
        }
        
        M[i][j] = -1;
        return false;
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        if(matrix.empty())
            return res;
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> P(m,vector<int>(n,-1));
        vector<vector<int>> A(m,vector<int>(n,-1));
        
        for(int j = 0;j<n;j++){
            P[0][j] = 1;
            A[m-1][j] = 1;
        }
        for(int i = 0;i<m;i++){
            P[i][0] = 1;
            A[i][n-1] = 1;
        }
//        printMatrix(P,m,n);
//        printMatrix(A,m,n);

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(P[i][j] == -1)
                    DFS(matrix,P,i,j,m,n);
                if(A[i][j] == -1)
                    DFS(matrix,A,i,j,m,n);
//                printMatrix(P,m,n);
//                printMatrix(A,m,n);
                
            }
        }
        
//        printMatrix(P,m,n);
//        printMatrix(A,m,n);
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(A[i][j] == 1 && P[i][j] == 1){
                    res.push_back({i,j});
                }
            }
        }
        
        return res;
    }
};

int main() {
    Solution S;
    vector<vector<int>> matrix = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    vector<vector<int>> res = S.pacificAtlantic(matrix);
    return 0;
}
