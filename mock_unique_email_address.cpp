//
//  mock_unique_email_address.cpp
//
//  Created by omlenka on 17/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

class Solution {
    string parseLocal(string s)
    {
        string res = "";
        for(char c: s)
        {
            if(c == '+')
                break;
            if(c == '.')
                continue;
            
            res += string(1,c);
        }
        
        return res;
    }
    string processEmail(string s)
    {
        string local,domain;
        string delimiter = "@";
        int i = s.find(delimiter);
        local = s.substr(0,i);
        domain = s.substr(i, s.length()-i);
        
        return parseLocal(local) + domain;
    }
public:
    int numUniqueEmails(vector<string>& emails)
    {
        unordered_set<string> S;
        
        for(string email:emails)
        {
            S.insert(processEmail(email));
        }
        return S.size();
    }
};
