//
//  reconstruct_itinerary_lc332.cpp
//
//  Created by omlenka on 03/01/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,set<string>> M;
        int no_of_tickets = tickets.size();
        for(vector<string> ticket:tickets){
            string from = ticket[0];
            string to = ticket[1];
            
            if(M.find(from) == M.end()){
                set<string> S;
                S.insert(to);
                M[from] = S;
            }
            else{
                M[from].insert(to);
            }
        }
        
        auto itr = M.find("JFK");
        stack<string> stk;
        stk.push("JFK");
        string insert = "";
        while(no_of_tickets){
            if(itr != M.end() && !itr->second.empty()){
                auto set_itr = itr->second.begin();
                string next_hop = *set_itr;
                stk.push(next_hop);
                itr->second.erase(set_itr);
                if(!insert.empty()){
                    itr->second.insert(insert);
                    insert.clear();
                    no_of_tickets++;
                }
                itr = M.find(next_hop);
                no_of_tickets--;
            }
            else{
                string to = stk.top();
                stk.pop();
                string from = stk.top();
                insert = to;
                itr = M.find(from);
            }
        }
        
        vector<string> res;
        while(!stk.empty()){
            string top = stk.top();
            stk.pop();
            res.push_back(top);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

int main() {
    Solution S;
//    vector<vector<string>> tickets = {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};
//    vector<vector<string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    vector<vector<string>> tickets = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
    vector<string> res = S.findItinerary(tickets);
    return 0;
}
