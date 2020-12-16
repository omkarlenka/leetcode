//
//  accounts_merge.cpp
//
//  Created by omlenka on 16/12/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

class Solution {
    unordered_multimap<string, set<string>>::iterator createNewEntry(unordered_multimap<string, set<string>> &M, vector<string> &account){
        set<string> S(account.begin()+1, account.end());
        return M.insert(make_pair(account[0],S));
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_multimap<string, set<string>> M;
        for(auto account : accounts){
            if(account.size() == 1)
                continue;
            int keys_count = M.count(account[0]);
            if(keys_count == 0){
                //User is not present
                createNewEntry(M, account);
            }
            else{
                //User is present
                auto itr_range = M.equal_range(account[0]);
                auto parent_itr = createNewEntry(M, account);
                auto itr = itr_range.first;
                while(itr != itr_range.second){
                    set<string> S = itr->second;
                    bool same_user = false;
                    
                    auto set_itr = S.begin();
                    while(set_itr != S.end()){
                        if(parent_itr->second.find(*set_itr) != parent_itr->second.end()){
                            same_user = true;
                            break;
                        }
                        set_itr++;
                    }
                    
                    if(same_user){
                        parent_itr->second.insert(itr->second.begin(), itr->second.end());
                        auto itr_tmp = itr;
                        itr++;
                        M.erase(itr_tmp);
                    }
                    else{
                        itr++;
                    }
                }
            }
        }
        
        vector<vector<string>> results;
        auto itr = M.begin();
        while(itr != M.end()){
            vector<string> result;
            string name = itr->first;
            vector<string> emails(itr->second.begin(), itr->second.end());
            
            result.push_back(name);
            result.insert(result.end(),emails.begin(), emails.end());
            results.push_back(result);
            itr++;
        }
        return results;
    }
};

int main() {
    Solution S;
    vector<vector<string>> accounts = {{"a","b","c"},{"a","b","x"},{"a","q","r"},{"b","e","t"}};
    vector<vector<string>> res = S.accountsMerge(accounts);
    return 0;
}
