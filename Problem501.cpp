class Solution {
public:
    unordered_map<int,int>mp;

    void isValid(TreeNode* root) {

        if(root==NULL) return;

        isValid(root->left);
        mp[root->val]++;
        isValid(root->right);

    }

    vector<int> findMode(TreeNode* root) {

        isValid(root);

        int maxi=0;
        for(auto it:mp){              //iterating in map
            if(it.second>maxi){        //it.second stores the frequency of elements
                maxi=it.second;        // updating maxi variable with the highest frequency encountered
            }
        }
        vector<int>ans;
        for(auto it:mp){
            if(it.second==maxi){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
