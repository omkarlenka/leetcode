//
//  main.cpp
//  max_xor_of_two_numbers_lc421.cpp
//
//  Created by omlenka on 02/02/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class TrieNode{
public:
    TrieNode *left;
    TrieNode *right;
    int endNumber;
    TrieNode(){
        left = NULL;
        right = NULL;
        endNumber = -1;
    }
};

class Trie{
    TrieNode *root;
public:
    Trie(){
        root = new TrieNode();
    }
    
    void insert(int val){
        int no_of_bits = 30;
        TrieNode *curr_root = root;
        while(no_of_bits >= 0){
            int bit = (val & (1 << no_of_bits) ? 1:0);
            
            if(bit == 1){
                if(!curr_root->right)
                    curr_root->right = new TrieNode();
                curr_root = curr_root->right;
            }
            else{
                if(!curr_root->left)
                    curr_root->left = new TrieNode();
                curr_root = curr_root->left;
            }
            no_of_bits--;
        }
        curr_root->endNumber = val;
    }
    
    int findMaxXOR(int val){
        
        TrieNode* curr_ptr = root;
        int no_of_bits = 30;
        
         while(no_of_bits >= 0){
            int bit = (val & (1 << no_of_bits--) ? 1:0);
             if(bit == 1){
                 if(curr_ptr->left){
                     curr_ptr = curr_ptr->left;
                 }
                 else{
                     curr_ptr = curr_ptr->right;
                 }
             }
             else{
                 if(curr_ptr->right){
                     curr_ptr = curr_ptr->right;
                 }
                 else{
                     curr_ptr = curr_ptr->left;
                 }
             }
        }
        return val ^ (curr_ptr->endNumber);
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *T = new Trie();
        for(int n:nums){
            T->insert(n);
        }
        
        int max_xor = INT_MIN;
        for(int n:nums){
            int res = T->findMaxXOR(n);
            if(res > max_xor){
                max_xor = res;
            }
        }
        
        return max_xor;
    }
};

int main() {
    Solution S;
    vector<int> nums = {32,18,29,46};
    cout << S.findMaximumXOR(nums) << endl;
    return 0;
}
