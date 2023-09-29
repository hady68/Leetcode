// Given the root of a binary tree, return the preorder traversal of its nodes' values.
// Example 1:
// Input: root = [1,null,2,3]
// Output: [1,2,3]

// Example 2:
// Input: root = []
// Output: []

// Example 3:
// Input: root = [1]
// Output: [1]
 

// Constraints:
// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100

//Solution -> Recursion

  void preorderfun(vector<int>& preorder,TreeNode* root){
         if(root == NULL){return;}
        preorder.push_back(root->val);
        preorderfun(preorder,root->left);
        preorderfun(preorder,root->right);
     }

    vector<int> preorderTraversal(TreeNode* root) {
         vector<int>preorder;
        preorderfun(preorder,root);
         return preorder;
}

// iterative using stack
class Solution {
public:
 vector<int> preorderTraversal(TreeNode* root) {
        vector<int>preorder;
        stack<TreeNode*>st;

        if(root == NULL){return preorder;}

        st.push(root);


        while(!st.empty()){
            TreeNode* top = st.top();
            st.pop();
            preorder.push_back(top->val);

            if(top->right!= NULL){
                st.push(top->right);
            }
            if(top->left!= NULL){
                st.push(top->left);
            }
        }

        return preorder;
    }
};
