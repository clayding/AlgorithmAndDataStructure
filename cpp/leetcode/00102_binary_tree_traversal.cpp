
// 相当于使用二维数组
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
    vector<vector<int>> result;
    int m_level = 0;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return result;
        }

        levelRec(root, m_level);
        return result;
    }

    void levelRec(TreeNode* root, int level) {
        int size = result.size();
        if(root == nullptr) {
            return;
        }
        if (size <= level) {
            result.push_back(vector<int>(1, root->val));
        } else {
            result[level].push_back(root->val);
        }

        levelRec(root->left, level + 1);
        levelRec(root->right,level + 1);
    }
};



//使用队列 queue
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root) {
            return ret;
        }
        queue<TreeNode*> nq;
        nq.push(root);

        while(!nq.empty()) {
            int level_size = nq.size();// 获取每一层的节点的数量
            ret.push_back(vector<int>());

            for(int i = 1; i <= level_size; ++i) {
                auto node = nq.front();
                nq.pop();
                ret.back().push_back(node->val);
                if (node->left) nq.push(node->left);
                if (node->right) nq.push(node->right);
            }
        }
        return ret;
    }
};
