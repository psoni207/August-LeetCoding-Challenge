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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int> > res;
        if(root == NULL)
            return res;

        map<int,vector<pair<int, int> > > m;
        map<int,vector<pair<int, int> > >::iterator it;

        queue<pair<struct TreeNode*,int> > level;
        level.push(make_pair(root,0));

        int degree = 0;
        while(!level.empty() )
        {
            pair<struct TreeNode *, int> curr;
            int count = level.size();

            while(count != 0){

                curr = level.front();
                level.pop();

                struct TreeNode *node = curr.first;
                int h = curr.second;

                m[h].push_back({node->val, degree});
                if( node->left )
                    level.push(make_pair(node->left,h-1) );
                if( node->right )
                    level.push(make_pair(node->right,h+1) );

                count -= 1;
            }

            degree += 1;

        }

        for( it = m.begin(); it != m.end(); it++){
            sort(it->second.begin(), it->second.end(), compareFunc);
            
            vector<int> temp;
            for(pair<int, int> p: it->second){
                temp.push_back(p.first);
            }
            res.push_back(temp);
        }

        return res;
        
    }
    
    static bool compareFunc(const pair<int, int> &a, const pair<int, int> &b){
        if( (a.second == b.second ) && (a.first < b.first) ){
            return true;
        }
                   
        return a.second < b.second;
    }
};