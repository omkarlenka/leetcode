//
//  valid_tic_tac_toe_state.cpp
//
//  Created by omlenka on 06/11/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    char getWinner(vector<string>& board){
        for(int i = 0;i<3;i++){
            if(board[i][0] != ' ' && board[i][0] == board[i][1]  && board[i][1] == board[i][2]){
                return board[i][0];
            }
            if(board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]){
                return board[0][i];
            }
        }
        if(board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
            return board[0][0];
        if(board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
            return board[0][2];
        return ' ';
    }
public:
    bool validTicTacToe(vector<string>& board) {
        int X = 0, O = 0;
        for(string row:board){
            for(char c: row){
                if(c == 'X')
                    X++;
                if(c == 'O')
                    O++;
            }
        }
        char winner = getWinner(board);
        if(winner == 'X'){
            if(X-O == 1)
                return true;
        }
        else if(winner == 'O'){
            if(O == X){
                return true;
            }
        }
        else{
            if(X-O == 0 || X-O == 1)
                return true;
        }
        return false;
    }
};

int main() {
    vector<string> board = {"XXO","XOX","OXO"};
    Solution S;
    cout << S.validTicTacToe(board) << endl;
   
    return 0;
}
