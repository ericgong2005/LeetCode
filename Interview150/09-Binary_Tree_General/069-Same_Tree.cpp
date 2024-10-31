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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p){
            return (!q);
        }
        if(!q){
            return false;
        }
        vector<TreeNode*> pcurrent ({p});
        vector<TreeNode*> qcurrent ({q});
        int i = 0;
        while(pcurrent.size() > i){
            if(pcurrent[i]->val != qcurrent[i]->val){
                return false;
            }
            if(pcurrent[i]->right && qcurrent[i]->right){
                pcurrent.push_back(pcurrent[i]->right);
                qcurrent.push_back(qcurrent[i]->right);
            }
            else if(pcurrent[i]->right || qcurrent[i]->right){
                return false;
            }
            if(pcurrent[i]->left && qcurrent[i]->left){
                pcurrent.push_back(pcurrent[i]->left);
                qcurrent.push_back(qcurrent[i]->left);
            }
            else if(pcurrent[i]->left || qcurrent[i]->left){
                return false;
            }
            i++;
        }
        return true;
    }
};