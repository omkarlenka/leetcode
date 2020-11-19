//
//  validate_ip_address.cpp
//
//  Created by omlenka on 19/11/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
    bool preProcessIPv4(string IP){
        if(IP[0] == '.' || IP[IP.length()-1] == '.')
            return false;
        int len = IP.length();
        for(int i = 0;i<len-1;i++){
            if(IP[i] == '.' && IP[i+1] == '.')
                return false;
        }
        return true;
    }
    bool preProcessIPv6(string IP){
        if(IP[0] == ':' || IP[IP.length()-1] == ':')
            return false;
        int len = IP.length();
        for(int i = 0;i<len-1;i++){
            if(IP[i] == ':' && IP[i+1] == ':')
                return false;
        }
        return true;
    }
    
    bool isIPv4(string IP){
        if(!preProcessIPv4(IP))
            return false;
        char *token = strtok(&IP[0],".");
        int count = 0;
        while(token != NULL){
            if(count > 4){
                return false;
            }
            int len = strlen(token);
            if((len > 1  && token[0] == '0') || (len > 3))
                return false;
            
            int num = 0;
            for(int i = 0;i<len;i++){
                if(!isdigit(token[i])){
                    return false;
                }
                num += (token[i]-'0')*(pow(10,len-i-1));
                if(num > 255)
                    return  false;
            }
            count++;
            token = strtok(NULL,".");
        }
        if(count == 4){
            return true;
        }
        return false;
    }
    
    bool isIPv6(string IP){
        if(!preProcessIPv6(IP))
            return false;
        char *token = strtok(&IP[0],":");
        int count = 0;
        while(token != NULL){
            if(count > 8){
                return false;
            }
            int len = strlen(token);
            if(len > 4)
                return false;
            
            for(int i = 0;i<len;i++){
                if(!isdigit(token[i])){
                    if((token[i] >= 'A' && token[i] <= 'F') || (token[i] >= 'a' && token[i] <= 'f')){
                        continue;
                    }
                    else{
                        return false;
                    }
                }
            }
            count++;
            token = strtok(NULL,":");
        }
        if(count == 8){
            return true;
        }
        return false;
    }
    
public:
    string validIPAddress(string IP) {
        string res;
        if(isIPv4(IP)){
            res = "IPv4";
        }
        else if(isIPv6(IP)){
            res = "IPv6";
        }
        else{
            res = "Neither";
        }
        return res;
    }
};

int main() {
    Solution S;
    cout << S.validIPAddress("") << endl;
    
    return 0;
}
