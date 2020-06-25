//
//  design_search_autocomplete_system.cpp
//
//  Created by omlenka on 31/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode*> children;
    //hotness will save the no. of times a sentence is typed
    //and contains valid value only for the end letter of sentence
    int hotness;
    TrieNode()
    {
        hotness = 0;
    }
};

class Trie
{
public:
    TrieNode* root;
    Trie()
    {
        root = new TrieNode();
    }

    void insert(TrieNode* root,string s, int hotness)
    {
        for(int i = 0;i<s.length();i++)
        {
            char c = s[i];

            if(root->children.find(c) == root->children.end())
            {
                root->children[c] = new TrieNode();
            }
            root = root->children[c];

            if(i == s.length() - 1)
            {
                root->hotness = hotness;
            }
        }
    }
};

class Comparator
{
public:
    bool operator()(pair<string, int> a, pair<string, int> b)
    {
        if(a.second > b.second)
            return true;
        else if(a.second == b.second && a.first < b.first)
            return true;

        return false;
    }
};

class AutocompleteSystem {
    Trie *T;
    TrieNode* curr;
    string prefix;
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times)
    {
        T = new Trie();
        for(int i = 0; i < sentences.size();i++)
        {
            T->insert(T->root, sentences[i], times[i]);
        }
        curr = T->root;
        prefix = "";
    }

    void autoComplete(TrieNode* n, string prefix, vector<pair<string,int>> &v)
    {
        if(n->hotness)
        {
            v.push_back(make_pair(prefix, n->hotness));
            if(v.size() > 3)
            {
                sort(v.begin(), v.end(), Comparator());
                v.pop_back();
            }
        }

        unordered_map<char, TrieNode*>::iterator itr;
        for(itr = n->children.begin(); itr != n->children.end(); itr++)
        {
            autoComplete(itr->second, prefix+string(1, itr->first), v);
        }
    }

    vector<string> input(char c)
    {
        vector<string> res;
        if(c == '#')
        {
            curr->hotness++;
            curr = T->root;
            prefix = "";
            return res;
        }
        if(curr->children.find(c) == curr->children.end())
        {
            T->insert(curr, string(1,c), 0);
            curr = curr->children[c];
        }
        else
        {
            prefix += string(1,c);
            curr = curr->children[c];

            TrieNode* n = curr;
            vector<pair<string,int>> v;
            autoComplete(curr, prefix, v);
            sort(v.begin(), v.end(), Comparator());
            for(int i = 0;i<v.size();i++)
            {
                res.push_back(v[i].first);
            }
        }

        return res;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */

int main()
{
    vector<string> sentences = {"i love you", "island","ironman", "i love leetcode"};
    vector<int> times = {5,3,2,2};
    AutocompleteSystem* S = new AutocompleteSystem(sentences, times);
    vector<string> res = S->input('i');
    res = S->input(' ');
    res = S->input('a');
    res = S->input('#');
    res = S->input('i');
    res = S->input(' ');
    res = S->input('a');
    res = S->input('#');
    res = S->input('i');
    res = S->input(' ');
    res = S->input('a');
    res = S->input('#');
    return 0;
}
