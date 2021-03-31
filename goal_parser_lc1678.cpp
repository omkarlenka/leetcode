//
//  goal_parser_lc1678.cpp
//
//  Created by omlenka on 31/03/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string interpret(string command) {
        string res = "";
        int i = 0;
        while(i < command.length()){
            if(command[i] =='G'){
                res += string(1,'G');
                i++;
            }
            else if(command[i] == '('){
                if(command[i+1] == ')'){
                    res += string(1,'o');
                    i+=2;
                }
                else{
                    res += "al";
                    i+= 4;
                }
            }
        }
        return res;
    }
};
