//
//  shortest_bridge_lc934.cpp
//
//  Created by omlenka on 01/03/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    // void printMatrix(vector<vector<int>>& A,int m, int n){
    //     for(int i = 0;i<m;i++){
    //         for(int j = 0;j<n;j++){
    //             cout << A[i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << "-----------------------";
    // }
    void dfs(vector<vector<int>>& A, int i, int j, int m, int n,queue<pair<int,int>> &Q){
        if(A[i][j] == 2)
            return;
        A[i][j] = 2;
        
        int count = 0;
        if(i+1 < m && (A[i+1][j] == 1 || A[i+1][j] == 2)){
            count++;
            dfs(A,i+1,j,m,n,Q);
        }
        if(i-1 >= 0 && (A[i-1][j] == 1 || A[i-1][j] == 2)){
            count++;
            dfs(A,i-1,j,m,n,Q);
        }
        if(j+1 < n && (A[i][j+1] == 1 || A[i][j+1] == 2)){
            count++;
            dfs(A,i,j+1,m,n,Q);
        }
        if(j-1 >= 0 && (A[i][j-1] == 1 || A[i][j-1] == 2)){
            count++;
            dfs(A,i,j-1,m,n,Q);
        }
        if(count < 4)
            Q.push(make_pair(i*1000+j,0));
    }
    
    void bfs(vector<vector<int>>& A, int m, int n, queue<pair<int,int>> &Q, int &res){
        // cout << Q.size() << endl;
        while(!Q.empty()){
            pair<int,int> top = Q.front();
            Q.pop();
            // cout << Q.size() << endl;
            // cout << top.first << endl;
            int X = (int)(top.first)/1000;
            int Y = (int)(top.first) % 1000;
            int D = top.second;
            
            if(A[X][Y] == 1){
                res = D;
                break;
            }
            // cout << X << " " << Y << endl;
            
            if(X+1 < m && A[X+1][Y] != 2){
                if(A[X+1][Y] == 1){
                    res = D+1;
                    break;
                }
                A[X+1][Y] = 2;
                Q.push(make_pair((X+1)*1000+Y,D+1));
            }
            if(X-1 >= 0 && A[X-1][Y] != 2){
                if(A[X-1][Y] == 1){
                    res = D+1;
                    break;
                }
                A[X-1][Y] = 2;
                Q.push(make_pair((X-1)*1000+Y,D+1));
            }
            if(Y+1 < n && A[X][Y+1] != 2){
                if(A[X][Y+1] == 1){
                    res = D+1;
                    break;
                }
                A[X][Y+1] = 2;
                Q.push(make_pair(X*1000+(Y+1),D+1));
            }
            if(Y-1 >= 0 && A[X][Y-1] != 2){
                if(A[X][Y-1] == 1){
                    res = D+1;
                    break;
                }
                A[X][Y-1] = 2;
                Q.push(make_pair(X*1000+(Y-1),D+1));
            }
        }
    }
public:
    int shortestBridge(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        queue<pair<int,int>> Q;
        for(int i = 0;i<m;i++){
            int j;
            for(j = 0;j<n;j++){
                if(A[i][j] == 1){
                    dfs(A,i,j,m,n,Q);
                    break;
                }
            }
            if(!Q.empty())
                break;
        }
        // printMatrix(A,m,n);
        int res = 0;
        bfs(A,m,n,Q,res);
        
        return res-1;
    }
};
