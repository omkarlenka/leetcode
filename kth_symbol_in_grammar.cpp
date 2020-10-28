//
//  kth_symbol_in_grammar.cpp
//
//  Created by omlenka on 28/10/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int kthGrammar(int N, int K) {
        if(N == 1)
            return 0;
        if(N == 2)
        {
            if(K == 1)
                return 0;
            else
                return 1;
        }
        int n = N-1;
        
        if(K<=pow(2,n-2))
            return kthGrammar(n-1, K);
        if(K>pow(2,n-2) && K <= pow(2,n-1))
            return !kthGrammar(n-1, K-pow(2,n-2));
        if(K > pow(2,n-1) && K <= (pow(2,n-1)+pow(2,n-2)))
            return !kthGrammar(n-1, K-pow(2,n-1));
        return kthGrammar(n-1, K-pow(2,n-1)-pow(2,n-2));
    }
};

int main() {
    Solution S;
    cout << S.kthGrammar(3, 2) << endl;
    
    return 0;
}
