//

//  decode_ways.cpp
//
//  Created by omlenka on 26/12/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if(len == 0){
            return len;
        }
        if(len == 1){
            if(s[0] == '0')
                return 0;
            else
                return 1;
        }
        
        vector<int> DP(len,0);
        if(s[len-1] != '0')
            DP[len-1] = 1;
        
        if(s[len-2] != '0'){
            if ((s[len-2]-'0')*10+(s[len-1]-'0') <= 26){
                DP[len-2] = 1 + DP[len-1];
            }
            else{
                DP[len-2] = DP[len-1];
            }
        }
        
        for(int i = len-3;i>=0;i--){
            if(s[i] == '0'){
                DP[i] = 0;
            }
            else{
                DP[i] = DP[i+1];
                if((s[i]-'0')*10+(s[i+1]-'0') <= 26){
                    DP[i] += DP[i+2];
                }
            }
        }
        return DP[0];
    }
};

int main() {
    Solution S;
    cout << S.numDecodings("2613") << endl;
    
    return 0;
}
