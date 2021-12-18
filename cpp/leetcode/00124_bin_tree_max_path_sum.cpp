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
    int maxPathSum(TreeNode* root) {
        int val = INT_MIN;
        maxPathSum(root, val);

        return val;
    }

    int maxPathSum(TreeNode* node, int& sum) {
        if (node == nullptr) return 0;

        int leftmax = max(0, maxPathSum(node->left, sum));
        int rightmax = max(0, maxPathSum(node->right, sum));
        
        sum = max(sum, leftmax + rightmax + node->val);

        return node->val + max(leftmax, rightmax);
    }
};
