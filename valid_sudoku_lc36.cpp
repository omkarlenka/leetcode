//
//  valid_sudoku_lc36.cpp
//
//  Created by omlenka on 19/01/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    bool isRowValid(vector<vector<char>>& board, int i){
        vector<bool> v(9, false);
        for(int j = 0;j<9;j++){
            if(board[i][j] == '.')
                continue;
            if(v[(board[i][j]-'0')-1])
                return false;
            v[(board[i][j]-'0')-1] = true;
        }
        return true;
    }
    
    bool isColValid(vector<vector<char>>& board, int j){
        vector<bool> v(9, false);
        for(int i = 0;i<9;i++){
            if(board[i][j] == '.')
                continue;
            if(v[(board[i][j]-'0')-1])
                return false;
            v[(board[i][j]-'0')-1] = true;
        }
        return true;
    }
    
    bool isSquareValid(vector<vector<char>>& board, int row, int col){
        vector<bool> v(9, false);
        int row_limit = row+3;
        int col_limit = col+3;
        for(int i = row;i<row_limit;i++){
            for(int j = col;j<col_limit;j++){
                if(board[i][j] == '.')
                    continue;
                if(v[(board[i][j]-'0')-1])
                    return false;
                v[(board[i][j]-'0')-1] = true;
            }
        }
        return true;
    }
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0;i<9;i++){
            if(!isRowValid(board, i))
                return false;
            if(!isColValid(board, i))
                return false;
        }
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                if((i == 0 ||  i == 3 || i == 6) && (j == 0 ||  j == 3 || j == 6)){
                    if(!isSquareValid(board, i, j))
                        return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution S;
    vector<vector<char>> board =
    {{'.','.','.','.','5','.','.','1','.'},
        {'.','4','.','3','.','.','.','.','.'},
        {'.','.','.','.','.','3','.','.','1'},
        {'8','.','.','.','.','.','.','2','.'},
        {'.','.','2','.','7','.','.','.','.'},
        {'.','1','5','.','.','.','.','.','.'},
        {'.','.','.','.','.','2','.','.','.'},
        {'.','2','.','9','.','.','.','.','.'},
        {'.','.','4','.','.','.','.','.','.'}};

//    {{'8','3','.','.','7','.','.','.','.'}
//        ,{'6','.','.','1','9','5','.','.','.'}
//        ,{'.','9','8','.','.','.','.','6','.'}
//        ,{'8','.','.','.','6','.','.','.','3'}
//        ,{'4','.','.','8','.','3','.','.','1'}
//        ,{'7','.','.','.','2','.','.','.','6'}
//        ,{'.','6','.','.','.','.','2','8','.'}
//        ,{'.','.','.','4','1','9','.','.','5'}
//        ,{'.','.','.','.','8','.','.','7','9'}};
    
    cout << S.isValidSudoku(board) << endl;

    return 0;
}
