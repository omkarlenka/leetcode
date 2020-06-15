//
//  reorder_data_in_log_files.cpp
//
//  Created by omlenka on 15/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

class Compare
{
public:
    bool operator()(const string &a, const string &b) const
    {
        string id1="", id2="", log1="",log2="";
        int i,j;
        for(i = 0;i<a.length();i++)
        {
            if(a[i] != ' ')
                id1 += string(1,a[i]);
            else
                break;
        }
        for(j = 0;j<b.length();j++)
        {
            if(b[j] != ' ')
                id2 += string(1,b[j]);
            else
                break;
        }
        
        log1 = a.substr(i+1,a.length()-i);
        log2 = b.substr(j+1,b.length()-j);
        if(log1 < log2)
            return true;
        
        if(log1 > log2)
            return false;
        
        return (id1 < id2);
    }
};
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs)
    {
        vector<string> letter_log;
        vector<string> digit_log;
        for(string a : logs)
        {
            string id;
            string log;
            int i;
            for(i = 0;i<a.length();i++)
            {
                if(a[i] != ' ')
                    id += string(1,a[i]);
                else
                    break;
            }
            log = a.substr(i+1,a.length()-i);
            if(isdigit(log[0]))
                digit_log.push_back(a);
            else
                letter_log.push_back(a);
        }
        sort(letter_log.begin(),letter_log.end(), Compare());
        letter_log.insert(letter_log.end(), digit_log.begin(), digit_log.end());
        return letter_log;
    }
};
