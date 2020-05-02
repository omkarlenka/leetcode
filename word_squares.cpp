//
//  word_squares.cpp
//
//  Created by omlenka on 02/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;
class Solution {
public:
    bool isSquare(vector<string> v)
    {
        int len = v.size();
        for(int i = 0; i < len; i++)
        {
            string s1 = v[i];
            string s2 = "";
            for(int j = 0; j < len; j++)
            {
                s2 += string(1,v[j][i]);
            }
            if(s1 != s2)
                return false;
        }
        return true;
    }
    
    void formSquares(vector<string>& words, vector<string> res_progress, vector<vector<string>> &res_final , int k, map<string, vector<string>> &M)
    {
        if(k == words[0].length())
        {
            if(isSquare(res_progress))
            {
                res_final.push_back(res_progress);
            }
            // else
            // {
            //     res_progress.erase(res_progress.begin()+res_progress.size()-1);
            // }
            return;
        }
        
        
        if(k == 0)
        {
            for(string word:words)
            {
                res_progress[k] = word;
                formSquares(words, res_progress, res_final,k+1, M);
            }
        }
        else
        {
            map<string, vector<string>>:: iterator itr;
            string key= "";
            for(int i = 0;i<k;i++)
                key += res_progress[i][k];
            itr = M.find(key);
            
            if(itr != M.end())
            {
                vector<string> v = itr->second;
                for(string w:v)
                {
                    res_progress[k] = w;
                    formSquares(words, res_progress, res_final,k+1, M);
                }
            }
        }
    }
    
    vector<vector<string>> wordSquares(vector<string>& words)
    {
        map<string, vector<string>> M;
        int word_len = words[0].length();
        for(string word : words)
        {
            for(int l = 1; l <= word_len; l++)
            {
                string key = word.substr(0,l);
                if(M.find(key) == M.end())
                {
                    vector<string> v;
                    v.push_back(word);
                    M[key] = v;
                }
                else
                {
                    M[key].push_back(word);
                }
            }
        }
        
        vector<vector<string>> res_final;
        vector<string> res_progress(word_len);
        formSquares(words, res_progress, res_final,0, M);
        return res_final;
    }
};
