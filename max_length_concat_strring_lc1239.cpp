//
//  max_length_concat_strring_lc1239.cpp
//
//  Created by omlenka on 16/04/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Comparator{
public:
    bool operator()(const string &a, const string &b){
        return (a.length() > b.length());
    }
};

class Solution {
    bool hasDup(string s){
        vector<bool> v(26,false);
        for(char c:s){
            if(v[c-'a']){
                return true;
            }
            v[c-'a'] = true;
        }
        return false;
    }
    
    void maxLengthUtil(string str, vector<string> &arr,int index, int &res){
        if(index == arr.size()){
            return;
        }
        //include
        if(!hasDup(str + arr[index])){
            res = max(res, int(str.length() + arr[index].length()));
            maxLengthUtil(str+arr[index],arr,index+1,res);
        }
        //exclude
        maxLengthUtil(str,arr,index+1,res);
    }
    
public:
    int maxLength(vector<string>& arr) {
        int res = 0;
        string str = "";
        for(int i = 0;i<arr.size();i++){
            maxLengthUtil(str, arr, i, res);
        }
        
        return res;
    }
};





