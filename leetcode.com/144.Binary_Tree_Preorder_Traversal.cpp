/* *
 *    Author:   Akasaka
 *    FileName: 144.Binary_Tree_Preorder_Traversal.cpp
 *    Created:  2020.01.10(UTC+0800) 13.50.41(星期五)
 * */

#include <bits/stdc++.h>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stn;
        stn.push(root);
        while(!stn.empty())
        {
            TreeNode* T = stn.top();
            stn.pop();
            ans.push_back(T->val);
            if(T->right) stn.push(T->right);
            if(T->left) stn.push(T->left);
        }
        return ans;
    }
};

int main()
{
    TreeNode* Troot;
    Troot = new TreeNode(5);

    Troot->left = new TreeNode(1);
    Troot->right = new TreeNode(9);

    Troot->left->right = new TreeNode(3);
    Troot->right->left = new TreeNode(6);
    Troot->right->right = new TreeNode(11);

    Troot->left->right->left = new TreeNode(2);
    Troot->left->right->right = new TreeNode(4);
    Troot->right->left->right = new TreeNode(8);
    Troot->right->right->left = new TreeNode(10);
    
    Troot->right->left->right->left = new TreeNode(7);

    vector<int> x = Solution().preorderTraversal(Troot);
    for(int i = 0; i < x.size(); i++)
        printf("%d ", x[i]);
    return 0;
}
