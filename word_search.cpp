//
//  word_search.cpp
//
//  Created by omlenka on 02/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    bool searchWord(vector<vector<char>>& board, string &word, int index, vector<vector<bool>> &visited, int i, int j, int r, int c)
    {
        visited[i][j] = true;
        
        if(index == word.length())
        {
            visited[i][j] = false;
            return false;
        }
        
        if(board[i][j] == word[index])
        {
            if(index == word.length()-1)
                return true;
            
            if(j-1 >= 0 && !visited[i][j-1])
            {
                if(searchWord(board, word, index+1, visited, i, j-1, r, c))
                    return true;
            }
            if(j+1 < c && !visited[i][j+1])
            {
                if(searchWord(board, word, index+1, visited, i, j+1, r, c))
                    return true;
            }
            if(i-1 >= 0 && !visited[i-1][j])
            {
                if(searchWord(board, word, index+1, visited, i-1, j, r, c))
                    return true;
            }
            if(i+1 < r && !visited[i+1][j])
            {
                if(searchWord(board, word, index+1, visited, i+1, j, r, c))
                    return true;
            }
        }
        visited[i][j] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        int r = board.size();
        int c = board[0].size();
        vector<vector<bool>> visited(r);
        vector<bool> v(c, false);
        for(int k = 0;k < r;k++)
            visited[k] = v;
        for(int i =0;i<r;i++)
        {
            for(int j = 0;j<c;j++)
            {
                if(board[i][j] == word[0])
                {
                    if(searchWord(board, word, 0, visited, i, j, r, c))
                        return true;
                }
            }
        }
        return false;
    }
};

