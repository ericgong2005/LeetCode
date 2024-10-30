#include <iostream>
#include <vector>

using namespace std;

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
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        int depth = 0;
        vector<TreeNode*> current;
        current.push_back(root);
        vector<TreeNode*> next;
        while(current.size() > 0){
            next = vector<TreeNode*> ();
            for(int i = 0; i < current.size(); i++){
                if(current[i]->right){
                    next.push_back(current[i]->right);
                }
                if(current[i]->left){
                    next.push_back(current[i]->left);
                }
            }
            current = next;
            depth++;
        }
        return depth;
    }
};