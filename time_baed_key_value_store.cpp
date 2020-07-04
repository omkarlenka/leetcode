//
//  time_baed_key_value_store.cpp
//
//  Created by omlenka on 04/07/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//
#include <string>
#include <unordered_map>

using namespace std;

class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, map<int,string>> M;
    TimeMap()
    {
        
    }
    
    void set(string key, string value, int timestamp)
    {
        auto itr = M.find(key);
        if(itr == M.end())
        {
            map<int,string> inner_M;
            inner_M[timestamp] = value;
            M[key] = inner_M;
        }
        else
        {
            M[key][timestamp] = value;
            
        }
    }
    
    string get(string key, int timestamp)
    {
        string res = "";
        if(M.find(key) != M.end())
        {
            auto itr = M[key].lower_bound(timestamp);
            if(itr->first == timestamp)
            {
                res = itr->second;
            }
            else if(itr != M[key].begin())
            {
                res = (prev(itr,1))->second;
            }
        }
        
        
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */



