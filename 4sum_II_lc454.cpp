//
//  4sum_II_lc454.cpp
//
//  Created by omlenka on 11/01/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res = 0;
        unordered_map<int, int> M;
        
        for(int c:C){
            for(int d:D){
                M[c+d]++;
            }
        }
        
        for(int a:A){
            for(int b:B){
                int sum = a+b;
                if(M.find(-1*sum) != M.end()){
                    res += M[-1*sum];
                }
            }
        }
        
        return res;
    }
};


int main() {
    Solution S;
    
    vector<int> A = {1,2,3,-1};
    vector<int> B = {-2,-1,-1,1};
    vector<int> C = {-1,2,0,-2};
    vector<int> D = {0,2,1,2};
    cout << S.fourSumCount(A, B, C, D);
    return 0;
}
