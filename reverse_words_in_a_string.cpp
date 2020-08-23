//
//  reverse_words_in_a_string.cpp
//
//  Created by omlenka on 23/08/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
    void reverse_str(string &s, int l, int r)
    {
        while(l < r)
            swap(s[l++],s[r--]);
    }
    
    void remove_spaces(string &s)
    {
        if(s.empty())
            return;
        int i = 0;
        int len = s.length();
        
        //trim space in start
        while(i< len && s[i] == ' ')
        {
            i++;
        }
        
        if(i > 0)
        {
            s.erase(0,i);
            len -= i;
        }
        i = 0;
        
        //trim space between words and end
        while(i < len)
        {
            while(s[i] != ' ')
            {
                i++;
                if(i == len)
                    return;
            }
            
            int j = i+1;
            while(j < len && s[j] == ' ')
                j++;
            
            if(j > i+1)
            {
                s.erase(i+1, j-i-1);
                len -= (j-i-1);
            }
            else
                i++;
        }
        if(len && s[len-1] == ' ')
        {
            s.erase(len-1,1);
        }
    }
public:
    string reverseWords(string s)
    {
        if(s.empty())
            return s;
        remove_spaces(s);
        reverse(s.begin(), s.end());
        
        int i = 0;
        while(i<s.length())
        {
            int j = i;
            while(j < s.length() && s[j] != ' ')
            {
                j++;
            }
            
            reverse_str(s, i, j-1);
            
            if(i == j)
                i++;
            else
                i = ++j;
        }
        
        return s;
    }
};

int main()
{
    string s = "   the    sky    is blue     ";
    Solution S;
    cout << S.reverseWords("  ");
    return 0;
}
