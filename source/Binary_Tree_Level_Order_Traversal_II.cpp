/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)
            return result;
            
        vector<vector<TreeNode*>> tmp;
        
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while(!nodeQueue.empty()){
            vector<TreeNode*> nodeVec;
            while(!nodeQueue.empty()){
                TreeNode* node = nodeQueue.front();
                nodeVec.push_back(node);
                nodeQueue.pop();
            }
            tmp.push_back(nodeVec);
            
            for(int i = 0; i < nodeVec.size(); ++i){
                if(nodeVec[i]->left != NULL)
                    nodeQueue.push(nodeVec[i]->left);
                if(nodeVec[i]->right != NULL)
                    nodeQueue.push(nodeVec[i]->right);
            }
        }
        
        for(int i = tmp.size() - 1; i >= 0; --i){
            vector<int> tmp_i;
            for(int j = 0; j < tmp[i].size(); ++j){
                tmp_i.push_back(tmp[i][j]->val);
            }
            result.push_back(tmp_i);
        }
        
        return result;
    }
};