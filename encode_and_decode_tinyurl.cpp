//
//  encode_and_decode_tinyurl.cpp
//
//  Created by omlenka on 22/11/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <cstdlib>

using namespace std;

class Solution {
    int counter = 0;
    unordered_map<int,string> shortToLong;  //<counter, longUrl>
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string prefix = "http://tinyurl.com";
        string shortUrl = prefix + to_string(counter);
        shortToLong[counter] = longUrl;
        counter++;
        
        return shortUrl;
    }
    
    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string counter_string;
        for(int i = shortUrl.length()-1;i>=0;i--){
            if(shortUrl[i] == '/')
                break;
            counter_string += string(1,shortUrl[i]);
        }
        reverse(counter_string.begin(), counter_string.end());
        int counter_int = atoi(counter_string.c_str());
        return shortToLong[counter_int];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
