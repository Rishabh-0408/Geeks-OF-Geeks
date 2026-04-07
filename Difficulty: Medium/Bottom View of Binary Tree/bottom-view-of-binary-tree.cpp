/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int> ans;
        if(root == nullptr){
            return ans;
        }
        queue<pair<Node*,int>> q;
        q.push({root,0});
        
        map<int,int> mpp;
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            Node* temp = it.first;
            int line = it.second;
            
            mpp[line] = temp->data;
            if(temp->left != nullptr){
                q.push({temp -> left, line - 1});
            }
            if(temp->right != nullptr){
                q.push({temp -> right, line + 1});
            }
        }
        for(auto it : mpp){
            ans.push_back(it.second);
        }
    }
};