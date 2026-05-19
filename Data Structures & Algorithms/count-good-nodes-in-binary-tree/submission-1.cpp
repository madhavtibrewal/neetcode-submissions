/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int checkIfGood(TreeNode* root, int maxi){
        if(!root) return 0;

        int res = 0;

        if(root->val >= maxi) {
            res = 1;
            maxi = root->val;
        }

        res += checkIfGood(root->left, maxi);
        res += checkIfGood(root->right, maxi);

        return res;
    }

    int goodNodes(TreeNode* root) {
        return checkIfGood(root, INT_MIN);
    }
};
