//
//  design_tic_tac_toe.cpp
//
//  Created by omlenka on 18/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <vector>

using namespace std;

class TicTacToe {
    vector<pair<int,int>> R;
    vector<pair<int,int>> C;
    vector<pair<int,int>> D;
    int n;
    
    void updateCell(vector<pair<int,int>> &V, int i, int player)
    {
        if(V[i].first == 0)
        {
            V[i] = make_pair(player,1);
        }
        else if(V[i].first == player)
        {
            V[i].second++;
        }
        else
        {
            V[i] = make_pair(-1,-1);
        }
    }
    
public:
    /** Initialize your data structure here. */
    TicTacToe(int n)
    {
        this->n = n;
        R.resize(n,pair<int,int>(0,0));
        C.resize(n,pair<int,int>(0,0));
        D.resize(2,pair<int,int>(0,0));
    }
    
    /** Player {player} makes a move at ({row}, {col}).
     @param row The row of the board.
     @param col The column of the board.
     @param player The player, can be either 1 or 2.
     @return The current winning condition, can be either:
     0: No one wins.
     1: Player 1 wins.
     2: Player 2 wins. */
    int move(int row, int col, int player)
    {
        updateCell(R, row, player);
        updateCell(C, col,player);
        
        if(n%2 && (row == n/2 && col == n/2))  //center, can claim both diagonals
        {
            updateCell(D,0,player);
            updateCell(D,1,player);
        }
        else
        {
            if(row == col)
            {
                updateCell(D,0,player);
            }
            else if(row + col == n-1)
                updateCell(D,1,player);
        }
        
        //Check Winner
        if(R[row].first == player && R[row].second == n)
            return player;
        if(C[col].first == player && C[col].second == n)
            return player;
        if(D[0].first == player && D[0].second == n)
            return player;
        if(D[1].first == player && D[1].second == n)
            return player;
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */


