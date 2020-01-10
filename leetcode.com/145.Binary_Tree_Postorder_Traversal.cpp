/* *
 *    Author:   Akasaka
 *    FileName: 145.Binary_Tree_Postorder_Traversal.cpp
 *    Created:  2020.01.10(UTC+0800) 14.12.55(星期五)
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> stn;
        stn.push(root);
        TreeNode* T;
        while(!stn.empty())
        {
            T = stn.top();
            stn.pop();
            ans.emplace_back(T->val);
            if(T->left) stn.push(T->left);
            if(T->right) stn.push(T->right);
        }
        reverse(ans.begin(), ans.end());
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

    vector<int> x = Solution().postorderTraversal(Troot);
    for(int i = 0; i < x.size(); i++)
        printf("%d ", x[i]);
    return 0;
}
