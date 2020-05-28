//
//  read_n_chars_given_read4.cpp
//
//  Created by omlenka on 25/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n)
    {
        //buf = new char[n];
        int i = 0;
        int chars = 0;
        
        while(true)
        {
            char * v = new char[4];
            int len = read4(v);
            for(int j = 0;j<len;j++)
            {
                if(i == n)
                    return i;
                buf[i++] = v[j];
            }
            if(len < 4)
                break;
        }
        
        return i;
    }
};
