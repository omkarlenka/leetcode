//
//  number_of_substrings_all_3_chars_lc1358.cpp
//
//  Created by omlenka on 13/03/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=0,b=0,c=0;
        
        int l = 0, r = 0;
        int res = 0;
        
        while(r < s.length()){
            if(s[r] == 'a'){
                a++;
            }
            else if(s[r] == 'b'){
                b++;
            }
            else if(s[r] == 'c'){
                c++;
            }
            
            while(a > 0 && b >0 && c > 0){
                res += s.length()-r;
                
                if(s[l] == 'a'){
                    a--;
                }
                else if(s[l] == 'b'){
                    b--;
                }
                else if(s[l] == 'c'){
                    c--;
                }
                l++;
            }
            r++;
        }
        return res;
    }
};
