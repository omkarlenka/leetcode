//
//  binary_tree_level_order_traversal.cpp
//
//  Created by omlenka on 26/07/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> res;
        int i = -1;
        queue<TreeNode*> Q;
        Q.push(root);
        bool first = true;
        while(first || !Q.empty())
        {
            if(Q.empty())
                break;
            TreeNode* n = Q.front();
            Q.pop();
            if(n == NULL)
            {
                first = true;
            }
            else
            {
                if(first)
                {
                    vector<int> v;
                    res.push_back(v);
                    i++;
                    Q.push(NULL);
                    first = false;
                }
                res[i].push_back(n->val);
                if(n->left)
                    Q.push(n->left);
                if(n->right)
                    Q.push(n->right);
            }
        }
        return res;
    }
};

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution S;
    vector<vector<int>> res = S.levelOrder(root);
    
    return 0;
}
