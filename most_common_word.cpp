//
//  most_common_word.cpp
//
//  Created by omlenka on 25/07/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    string convertToLower(string s)
    {
        string s1;
        for(char c:s)
        {
            s1 += string(1,tolower(c));
        }
        return s1;
    }
public:
    string mostCommonWord(string para, vector<string>& banned)
    {
        unordered_set<string> blacklist;
        unordered_map<string, int> count;
        for(string word : banned)
        {
            blacklist.insert(word);
        }
        
        int max_freq = INT_MIN;
        string res;
        int start = 0;
        int end = 0;
        while(end <= para.length())
        {
            if(end == para.length() || para[end] == ' ' || para[end] == '!' || para[end] == '?' || para[end] == '\'' || para[end] == ',' || para[end] == ';' || para[end] == '.')
            {
                if(start == end)
                {
                    start++;
                    end++;
                    continue;
                }
                string word = para.substr(start,end-start);
                start = end + 1;
                end = start;
                word = convertToLower(word);
                
                if(blacklist.find(word) == blacklist.end())
                {
                    count[word]++;
                    if(count[word] > max_freq)
                    {
                        max_freq = count[word];
                        res = word;
                    }
                }
            }
            else
                end++;
        }
        return res;
    }
};

int main()
{
    Solution S;
    string para = "a, a, a, a, b,b,b,c, c";
    
    vector<string> banned = {"a"};
    cout << S.mostCommonWord(para, banned) << endl;
    return 0;
}
