//
//  strobogrammatic_number_II.cpp
//
//  Created by omlenka on 28/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> findStrobogrammatic(int n)
{
    vector<string> res;
    if(n == 1)
    {
        res.push_back("0");
        res.push_back("1");
        res.push_back("8");
    }
    else if (n == 2)
    {
        res.push_back("11");
        res.push_back("69");
        res.push_back("88");
        res.push_back("96");
    }
    else if(n%2 != 0)
    {
        vector<string> res1 = findStrobogrammatic(n-1);
        for(string s:res1)
        {
        //add 0
            res.push_back(s.substr(0,n/2) + "0" + s.substr(n/2,n/2));
        //add 1
            res.push_back(s.substr(0,n/2) + "1" + s.substr(n/2,n/2));
        //add 8
            res.push_back(s.substr(0,n/2) + "8" + s.substr(n/2,n/2));
        }
    }
    else if(n%2 == 0)
    {
        vector<string> res1 = findStrobogrammatic(n-2);
        for(string s: res1)
        {
            //add 00
            res.push_back(s.substr(0,n/2-1) + "00" + s.substr(n/2-1,n/2-1));
            //add 11
            res.push_back(s.substr(0,n/2-1) + "11" + s.substr(n/2-1,n/2-1));
            //add 69
            res.push_back(s.substr(0,n/2-1) + "69" + s.substr(n/2-1,n/2-1));
            //add 88
            res.push_back(s.substr(0,n/2-1) + "88" + s.substr(n/2-1,n/2-1));
            //add 96
            res.push_back(s.substr(0,n/2-1) + "96" + s.substr(n/2-1,n/2-1));
        }
    }
    return res;
}

int main()
{
    vector<string> res = findStrobogrammatic(10);
    return 0;
}
