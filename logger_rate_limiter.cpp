//
//  logger_rate_limiter.cpp
//
//  Created by omlenka on 07/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
class Logger {
    unordered_map<string, int> m;
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
     If this method returns false, the message will not be printed.
     The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        unordered_map<string, int>::iterator itr;
        itr = m.find(message);
        bool res = false;
        if(itr != m.end())
        {
            if(timestamp - itr->second < 10)
            {
                res = false;
            }
            else
            {
                res = true;
                m[message] = timestamp;
            }
            
        }
        else
        {
            m[message] = timestamp;
            res = true;
        }
        return res;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
