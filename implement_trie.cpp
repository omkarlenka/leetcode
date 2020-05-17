//
//  implement_trie.cpp
//
//  Created by omlenka on 17/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord;
    
    TrieNode()
    {
        endOfWord = false;
    }
};

class Trie {
    TrieNode* trieRoot = NULL;
public:
    /** Initialize your data structure here. */
    Trie()
    {
        trieRoot = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *root = trieRoot;
        for(int i = 0;i<word.length();i++)
        {
            char c = word[i];
            
            if(root->children.find(c) == root->children.end())
            {
                root->children[c] = new TrieNode();
                root = root->children[c];
            }
            else
            {
                root = root->children[c];
            }
            if(i == word.length() -1)
                root->endOfWord = true;
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *root = trieRoot;
        bool found = true;
        for(int i = 0;i<word.length();i++)
        {
            char c = word[i];
            if(root->children.find(c) == root->children.end())
            {
                found = false;
                break;
            }
            else
            {
                root = root->children[c];
            }
            if(i == word.length() - 1)
            {
                if(root->endOfWord  == false)
                {
                    found = false;
                    break;
                }
            }
            
        }
        return found;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *root = trieRoot;
        bool found = true;
        for(int i = 0;i<prefix.length();i++)
        {
            char c = prefix[i];
            if(root->children.find(c) == root->children.end())
            {
                found = false;
                break;
            }
            else
            {
                root = root->children[c];
            }
        }
        return found;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
