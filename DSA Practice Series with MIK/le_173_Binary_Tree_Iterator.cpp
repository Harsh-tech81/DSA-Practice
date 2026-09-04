class BSTIterator {
public:
    stack<int> st;
    void reverseInorder(TreeNode* root) {
        if (!root)
            return;
        reverseInorder(root->right);
        st.push(root->val);
        reverseInorder(root->left);
    }
    BSTIterator(TreeNode* root) { reverseInorder(root); }

    int next() {
        int res = st.top();
        st.pop();
        return res;
    }

    bool hasNext() { return st.size(); }
};