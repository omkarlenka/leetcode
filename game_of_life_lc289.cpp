//
//  game_of_life_lc289.cpp
//
//  Created by omlenka on 31/12/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int getCount(vector<vector<int>>& board, int i, int j, int m, int n){
        int count = 0;
        
        if(j+1 < n && (board[i][j+1] == 1 || board[i][j+1] == 2)){
            count++;
        }
        if(j-1 >= 0 && (board[i][j-1] == 1 || board[i][j-1] == 2)){
            count++;
        }
        
        if(i+1 < m){
            if(board[i+1][j] == 1 || board[i+1][j] == 2){
                count++;
            }
            if(j+1 < n && (board[i+1][j+1] == 1 || board[i+1][j+1] == 2))
                count++;
            if(j-1 >= 0 && (board[i+1][j-1] == 1 || board[i+1][j-1] == 2)){
                count++;
            }
        }
        if(i-1 >= 0){
            if(board[i-1][j] == 1 || board[i-1][j] == 2){
                count++;
            }
            if(j+1 < n && (board[i-1][j+1] == 1 || board[i-1][j+1] == 2))
                count++;
            if(j-1 >= 0 && (board[i-1][j-1] == 1 || board[i-1][j-1] == 2)){
                count++;
            }
        }
        return count;
    }
    void revertStates(vector<vector<int>>& board, int m, int n){
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j] == 2){
                    board[i][j] = 0;
                }
                else if(board[i][j] == 3){
                    board[i][j] = 1;
                }
            }
        }
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        //1: state change to 2
        //0: state change to 3
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i<m;i++){
            for(int j = 0;j<n;j++){
                int c = getCount(board, i, j, m, n);
                if(board[i][j]){
                    if(c != 2 && c != 3){
                        board[i][j] = 2;
                    }
                }
                else{
                    if(c == 3){
                        board[i][j] = 3;
                    }
                }
            }
        }
        revertStates(board, m, n);
    }
};

int main() {
    vector<vector<int>> board = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    Solution S;
    S.gameOfLife(board);
    
    return 0;
}
