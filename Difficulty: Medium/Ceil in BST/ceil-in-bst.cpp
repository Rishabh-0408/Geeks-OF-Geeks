class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        if(root == nullptr){
            return -1;
        }
        if(root->data == x){
            return root->data;
        }
        if(root->data < x){
            return findCeil(root->right,x);
        }
        int leftCeil = findCeil(root->left,x);
        
        return (leftCeil >= x) ? leftCeil : root->data;
    }
};
