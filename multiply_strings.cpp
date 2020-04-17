//
//  multiply_strings.cpp
//
//  Created by omlenka on 17/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string addRes(vector<string> v)
{
    int lc =v[v.size()-1].length();
    for(int i = 0;i<v.size()-1;i++)
    {
        int len = v[i].length();
        for(int  j = 0;j<lc-len;j++)
            v[i] = '0' + v[i];
    }
    string res;
    int val = 0, carry = 0;
    for(int  j =  lc-1;j>=0;j--)
    {
        int sum = carry;
        for(int i = 0;i<v.size();i++)
        {
            sum += (v[i][j]-'0');
        }
        if(sum >= 10)
        {
            val = sum %10;
            carry = sum/10;
        }
        else{
            val = sum;
            carry = 0;
        }
        res += val+'0';
    }
    if(carry)
        res += carry+'0';
    reverse(res.begin(), res.end());
    return res;
}

string multiply(string num1, string num2)
{
    if(num1 == "0" || num2 == "0")
        return "0";
    string larger,smaller;
    if(num1.length() > num2.length())
    {
        larger = num1;
        smaller = num2;
    }
    else
    {
        larger = num2;
        smaller = num1;
    }
    
    int l = larger.length();
    int s = smaller.length();
    
    vector<string> sum;
    
    for(int i = s-1;i>=0;i--)
    {
        string res = "";
        int v = 0,c = 0;
        for(int j = l-1;j>=0;j--)
        {
            int x = (smaller[i]-'0') * (larger[j]-'0')+c;
            if(x >= 0)
            {
                v = x%10;
                c = x/10;
            }
            else
            {
                v = x;
                c = 0;
            }
            res += v+'0';
        }
        if(c)
            res+=c+'0';
        reverse(res.begin(), res.end());
        for(int k = 0;k<s-i-1;k++)
            res+='0';
        sum.push_back(res);
    }
    return addRes(sum);
}

int main()
{
    string s1 = "999";
    string s2 = "999";
    cout << multiply(s1, s2) << endl;
    return 0;
}
