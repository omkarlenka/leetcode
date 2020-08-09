//
//  partition_labels.cpp
//
//  Created by omlenka on 09/08/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S)
    {
        unordered_map<char,pair<int,int>> M;
        vector<int> res;
        int partition = 0;
        
        for (int i = 0;i<S.length();i++)
        {
            if(M.find(S[i]) == M.end())
            {
                M[S[i]] = make_pair(i,i);
            }
            else
            {
                M[S[i]].second = i;
            }
        }
        
        while(partition != S.length())
        {
            int start = M[S[partition]].first;
            int end = M[S[partition]].second;
            for(int i = start+1;i<=end;i++)
            {
                if(M[S[i]].second > end)
                    end = M[S[i]].second;
            }
            res.push_back(end-start+1);
            partition = end+1;
        }
        return res;
    }
};

int main()
{
    Solution S;
    vector<int> res =  S.partitionLabels("ababcbacadefegdehijhklijaz");
    return 0;
}
