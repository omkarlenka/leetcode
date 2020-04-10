//
//  unique_email_address.cpp
//
//  Created by omlenka on 10/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

class Solution {
    string  parseAddress(string s)
    {
        string newString = "";
        bool domainName = false;
        bool plusFound = false;
        for(char c : s)
        {
            if(c == '@')
                domainName = true;
            if(c == '+')
                plusFound = true;
            
            if(domainName)
            {
                newString += c;
            }
            else
            {
                if(!plusFound && c != '.')
                    newString += c;
            }
        }
        return newString;
    }
public:
    int numUniqueEmails(vector<string>& emails)
    {
        unordered_set<string> us;
        for(string email: emails)
        {
            string s = parseAddress(email);
            us.insert(s);
        }
        
        return us.size();
    }
};
