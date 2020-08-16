//
//  surrounded_regions.cpp
//
//  Created by omlenka on 16/08/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void DFS(vector<vector<char>> &board, int curr_row, int curr_col, int &row, int &col, char src, char dst)
    {
        board[curr_row][curr_col] = dst;
        
        if(curr_row+1 < row && board[curr_row+1][curr_col] == src)
        {
            DFS(board, curr_row+1, curr_col, row, col, src, dst) ;
        }
        if(curr_row-1 >= 0 && board[curr_row-1][curr_col] == src)
        {
            DFS(board, curr_row-1, curr_col, row, col, src, dst) ;
        }
        if(curr_col+1 < col && board[curr_row][curr_col+1] == src)
        {
            DFS(board, curr_row, curr_col+1, row, col, src, dst) ;
        }
        if(curr_col-1 >= 0 && board[curr_row][curr_col-1] == src)
        {
            DFS(board, curr_row, curr_col-1, row, col, src, dst) ;
        }
    }
    void solveUtil(vector<vector<char>>& board, int &row, int &col)
    {
        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
public:
    void solve(vector<vector<char>>& board)
    {
        int row = board.size();
        if(!row)
            return;
        
        int col = board[0].size();
        
        for(int j = 0;j<col;j++)  //row = 0
        {
            if(board[0][j] == 'O')
                DFS(board, 0, j, row, col, 'O', 'Y');
        }
        for(int j = 0;j<col;j++)  //row-1
        {
            if(board[row-1][j] == 'O')
                DFS(board, row-1, j, row, col, 'O', 'Y');
        }
        for(int i=0;i<row;i++) //col = 0
        {
            if(board[i][0] == 'O')
                DFS(board, i, 0, row, col, 'O', 'Y');
        }
        for(int i=0;i<row;i++) //col = col-1
        {
            if(board[i][col-1] == 'O')
                DFS(board, i, col-1, row, col, 'O', 'Y');
        }
        
        solveUtil(board, row, col);
        
        for(int j = 0;j<col;j++)  //row = 0
        {
            if(board[0][j] == 'Y')
                DFS(board, 0, j, row, col, 'Y', 'O');
        }
        for(int j = 0;j<col;j++)  //row-1
        {
            if(board[row-1][j] == 'Y')
                DFS(board, row-1, j, row, col, 'Y','O');
        }
        for(int i=0;i<row;i++) //col = 0
        {
            if(board[i][0] == 'Y')
                DFS(board, i, 0, row, col, 'Y','O');
        }
        for(int i=0;i<row;i++) //col = col-1
        {
            if(board[i][col-1] == 'Y')
                DFS(board, i, col-1, row, col,'Y','O');
        }
    }
};

int main()
{
    Solution S;
    vector<vector<char>> v =
    {{'O','X','X','X','X','X','O','O'},{'O','O','O','X','X','X','X','O'},{'X','X','X','X','O','O','O','O'},{'X','O','X','O','O','X','X','X'},{'O','X','O','X','X','X','O','O'},{'O','X','X','O','O','X','X','O'},{'O','X','O','X','X','X','O','O'},{'O','X','X','X','X','O','X','X'}};
    
    S.solve(v);
    return 0;
}
