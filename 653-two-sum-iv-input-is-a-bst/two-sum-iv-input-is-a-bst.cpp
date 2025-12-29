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
class LDR{
    public:
    stack<TreeNode*> st;
    LDR(TreeNode* root)
    {
        while(root)
        {
            st.push(root);
            root = root->left;
        }
    }
    TreeNode* getNext()
    {
        TreeNode* n = st.top();
        st.pop();
        TreeNode* root = n-> right;
        while(root)
        {
            st.push(root);
            root = root->left;
        }
        return n;
    }
};
class RDL{
    public:
    stack<TreeNode*> st;
    RDL(TreeNode* root)
    {
        while(root)
        {
            st.push(root);
            root = root->right;
        }
    }
    TreeNode* getNext()
    {
        TreeNode* n = st.top();
        st.pop();
        TreeNode* root = n->left;
        while(root)
        {
            st.push(root);
            root = root->right;
        }
        return n;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        LDR* obj1 = new LDR(root);
        RDL* obj2 = new RDL(root);
        TreeNode* p1 = obj1->getNext();
        TreeNode* p2 = obj2->getNext();
        while(p1!=p2)
        {
            int sum = p1->val + p2->val;
            if(sum == k) return true;
            else if(sum > k) p2 = obj2->getNext();
            else p1 = obj1->getNext();  
        }
        return false;
    }
};