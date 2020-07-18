//
//  prison_cells_after_n_days
//
//  Created by omlenka on 18/07/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
    string  getNext(string S)
    {
        string res(8,'0');
        res[0] = '0';
        res[7] = '0';
        for(int i = 1;i<7;i++)
        {
            if(S[i-1] == S[i+1])
                res[i] = '1';
            else
                res[i] = '0';
        }
        
        return res;
    }
    void getResult(string S, vector<int> &res)
    {
        for(char c: S)
            res.push_back(c-'0');
    }
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N)
    {
        unordered_map<string, int> M1;
        unordered_map<int, string> M2;
        vector<int> res;
        
        string S="";
        for(int n : cells)
        {
            S += string(1,n+'0');
        }
        
        int day = 0;
        
        M1[S] =  day;
        M2[day] = S;
        
        while(true)
        {
            S = getNext(S);
            day++;
            if(M1.find(S) != M1.end())
                break;
            
            M1[S] =  day;
            M2[day] = S;
            if(day == N)
            {
                getResult(S,res);
                return res;
            }
        }
        
        auto itr = M1.find(S);
        int d1 = itr->second;
        int d2 = day;
        int repeat = d2-d1;
        int r = (N-d1) % repeat;
        
        S = M2[d1+r];
        
        getResult(S,res);
        return res;
    }
};

int main()
{
    Solution S;
    vector<int> cells = {0,1,0,1,1,0,0,1};
    vector<int> res = S.prisonAfterNDays(cells, 43);
    return 0;
}
