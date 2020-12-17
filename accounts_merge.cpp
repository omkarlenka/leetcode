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
    int count = 0;
    void createNewEntry(unordered_multimap<string, set<string>> &M, vector<string> account){
        set<string> S(account.begin()+1, account.end());
        M.insert(make_pair(account[0],S));
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
                set<string> parent_set(account.begin()+1, account.end());
                auto itr = itr_range.first;
                while(itr != itr_range.second){
                    set<string> S = itr->second;
                    bool same_user = false;
                    
                    auto set_itr = S.begin();
                    while(set_itr != S.end()){
                        if(parent_set.find(*set_itr) != parent_set.end()){
                            same_user = true;
                            break;
                        }
                        set_itr++;
                    }
                    
                    if(same_user){
                        parent_set.insert(itr->second.begin(), itr->second.end());
                        auto itr_tmp = itr;
                        itr++;
                        M.erase(itr_tmp);
                    }
                    else{
                        itr++;
                    }
                }
                M.insert(make_pair(account[0],parent_set));
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
    vector<vector<string>> accounts = {{"David","David35@m.co","David38@m.co","David85@m.co","David9@m.co","David38@m.co","David3@m.co","David13@m.co","David64@m.co","David16@m.co"},{"Isa","Isa74@m.co","Isa21@m.co","Isa26@m.co","Isa82@m.co","Isa66@m.co","Isa74@m.co","Isa63@m.co","Isa75@m.co","Isa6@m.co"},{"Bob","Bob96@m.co","Bob74@m.co","Bob84@m.co","Bob15@m.co","Bob49@m.co","Bob17@m.co","Bob14@m.co","Bob50@m.co","Bob85@m.co"},{"John","John76@m.co","John0@m.co","John93@m.co","John79@m.co","John89@m.co","John64@m.co","John70@m.co","John44@m.co","John19@m.co"},{"Lily","Lily19@m.co","Lily69@m.co","Lily26@m.co","Lily22@m.co","Lily81@m.co","Lily39@m.co","Lily11@m.co","Lily47@m.co","Lily61@m.co"},{"David","David89@m.co","David28@m.co","David87@m.co","David94@m.co","David91@m.co","David81@m.co","David26@m.co","David23@m.co","David68@m.co"},{"Bob","Bob70@m.co","Bob78@m.co","Bob93@m.co","Bob82@m.co","Bob95@m.co","Bob73@m.co","Bob63@m.co","Bob3@m.co","Bob95@m.co"},{"David","David77@m.co","David3@m.co","David42@m.co","David13@m.co","David51@m.co","David41@m.co","David72@m.co","David7@m.co","David35@m.co"},{"John","John39@m.co","John21@m.co","John61@m.co","John21@m.co","John68@m.co","John65@m.co","John81@m.co","John3@m.co","John54@m.co"},{"Ethan","Ethan42@m.co","Ethan41@m.co","Ethan56@m.co","Ethan66@m.co","Ethan16@m.co","Ethan14@m.co","Ethan60@m.co","Ethan2@m.co","Ethan69@m.co"},{"David","David76@m.co","David98@m.co","David8@m.co","David67@m.co","David39@m.co","David96@m.co","David24@m.co","David98@m.co","David29@m.co"},{"Bob","Bob54@m.co","Bob95@m.co","Bob2@m.co","Bob66@m.co","Bob39@m.co","Bob87@m.co","Bob71@m.co","Bob99@m.co","Bob31@m.co"},{"Ethan","Ethan78@m.co","Ethan92@m.co","Ethan20@m.co","Ethan76@m.co","Ethan77@m.co","Ethan86@m.co","Ethan87@m.co","Ethan74@m.co","Ethan69@m.co"},{"Gabe","Gabe14@m.co","Gabe83@m.co","Gabe10@m.co","Gabe84@m.co","Gabe24@m.co","Gabe80@m.co","Gabe41@m.co","Gabe67@m.co","Gabe71@m.co"},{"Ethan","Ethan19@m.co","Ethan98@m.co","Ethan75@m.co","Ethan88@m.co","Ethan0@m.co","Ethan71@m.co","Ethan6@m.co","Ethan92@m.co","Ethan21@m.co"},{"Ethan","Ethan73@m.co","Ethan96@m.co","Ethan99@m.co","Ethan63@m.co","Ethan7@m.co","Ethan48@m.co","Ethan64@m.co","Ethan50@m.co","Ethan14@m.co"},{"Ethan","Ethan7@m.co","Ethan18@m.co","Ethan81@m.co","Ethan69@m.co","Ethan59@m.co","Ethan37@m.co","Ethan30@m.co","Ethan20@m.co","Ethan30@m.co"},{"Bob","Bob36@m.co","Bob0@m.co","Bob61@m.co","Bob71@m.co","Bob41@m.co","Bob31@m.co","Bob39@m.co","Bob56@m.co","Bob43@m.co"},{"Bob","Bob8@m.co","Bob21@m.co","Bob81@m.co","Bob85@m.co","Bob21@m.co","Bob12@m.co","Bob27@m.co","Bob78@m.co","Bob99@m.co"},{"Lily","Lily4@m.co","Lily78@m.co","Lily1@m.co","Lily11@m.co","Lily22@m.co","Lily52@m.co","Lily46@m.co","Lily96@m.co","Lily49@m.co"},{"Lily","Lily49@m.co","Lily81@m.co","Lily96@m.co","Lily11@m.co","Lily70@m.co","Lily68@m.co","Lily73@m.co","Lily45@m.co","Lily84@m.co"}};
        
    vector<vector<string>> res = S.accountsMerge(accounts);
    return 0;
}
