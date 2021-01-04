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
    void findItineraryUtil(unordered_map<string,multiset<string>> &M, string src, int &no_of_tickets, vector<string> &res){
        res.push_back(src);
        if(no_of_tickets == 0)
            return;
        auto itr = M[src].begin();
        int i = 0;
        while(itr != M[src].end()){
            string dst = *itr;
            M[src].erase(itr);
            findItineraryUtil(M, dst, --no_of_tickets, res);
            if(no_of_tickets == 0)
                return;
            //failure, add back edge
            M[src].insert(dst);
            no_of_tickets++;
            i++;
            itr = next(M[src].begin(),i);
        }
        res.pop_back();
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> M;
        int no_of_tickets = tickets.size();
        for(vector<string> ticket:tickets){
            string from = ticket[0];
            string to = ticket[1];
            
            if(M.find(from) == M.end()){
                multiset<string> S;
                S.insert(to);
                M[from] = S;
            }
            else{
                M[from].insert(to);
            }
        }
        vector<string> res;
        string start = "JFK";
        findItineraryUtil(M, start, no_of_tickets, res);
        return res;
    }
};

int main() {
    Solution S;
    //    vector<vector<string>> tickets = {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};
    //    vector<vector<string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    //    vector<vector<string>> tickets = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
    //    vector<vector<string>> tickets = {{"JFK","DEF"},{"JFK","MNO"},{"MNO","JFK"},{"DEF","PQR"}};
    //    vector<vector<string>> tickets = {{"EZE","AXA"},{"TIA","ANU"},{"ANU","JFK"},{"JFK","ANU"},{"ANU","EZE"},{"TIA","ANU"},{"AXA","TIA"},{"TIA","JFK"},{"ANU","TIA"},{"JFK","TIA"}};
    //    vector<vector<string>> tickets = {{"MEL","PER"},{"SYD","CBR"},{"AUA","DRW"},{"JFK","EZE"},{"PER","AXA"},{"DRW","AUA"},{"EZE","SYD"},{"AUA","MEL"},{"DRW","AUA"},{"PER","ANU"},{"CBR","EZE"},{"EZE","PER"},{"MEL","EZE"},{"EZE","MEL"},{"EZE","TBI"},{"ADL","DRW"},{"ANU","EZE"},{"AXA","ADL"}};
    //    vector<vector<string>> tickets = {{"JFK","ABC"},{"ABC","PQR"},{"PQR","ABC"},{"ABC","MNO"}};
    vector<vector<string>> tickets = {{"JFK","DEF"},{"JFK","MNO"},{"MNO","ABC"},{"DEF","PQR"}};
    vector<string> res = S.findItinerary(tickets);
    return 0;
}
