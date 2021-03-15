//
//  accounts_merge_lc721.cpp
//
//  Created by omlenka on 15/03/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

class Solution {
    string find(string u, unordered_map<string,string> &M){
        while(u != M[u]){
            u = M[u];
        }
        return u;
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,string> name;
        unordered_map<string,string> M;
        
        for(auto account:accounts){
            string account_name = account[0];
            int account_size = account.size();
            for(int i = 1;i<account_size;i++){
                M[account[i]] = account[i];
                name[account[i]] = account_name;
            }
        }
        
        for(auto account:accounts){
            string parent_email = find(account[1],M);
            int account_size = account.size();
            for(int i =2;i<account_size;i++){
                M[find(account[i],M)] = parent_email;
            }
        }
        
        unordered_map<string,set<string>> res_tmp;
        vector<vector<string>> res;
        
        for(auto itr = M.begin();itr != M.end();itr++){
            string email = find(itr->second,M);
            if(res_tmp.find(email) == res_tmp.end()){
                res_tmp[email] = set<string>();
            }
            res_tmp[email].insert(itr->first);
        }
        
        for(auto itr = res_tmp.begin();itr != res_tmp.end();itr++){
            vector<string> r_tmp;
            r_tmp.push_back(name[itr->first]);
            vector<string> copy(itr->second.begin(), itr->second.end());
            r_tmp.insert(r_tmp.end(), copy.begin(), copy.end());
            res.push_back(r_tmp);
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<vector<string>> accounts = {{"John","johnsmith@mail.com","john_newyork@mail.com"},{"John","johnsmith@mail.com","john00@mail.com"},{"Mary","mary@mail.com"},{"John","johnnybravo@mail.com"}};
        
    vector<vector<string>> res = S.accountsMerge(accounts);
    return 0;
}
