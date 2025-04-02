#include<iostream>
using namespace std;
#include<stack>
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x): val(x),left(NULL),right(NULL){};
};

class DFS{
    public:
        void preorder(TreeNode* root)
        {
            if(!root) return;
            stack<TreeNode*>s;
            s.push(root);
            cout<<"The preorder of the given tree : ";
            while(!s.empty())
            {
                TreeNode* node = s.top();
                s.pop();
                cout<<node->val<<" ";
                if(node->right) s.push(node->right);
                if(node->left) s.push(node->left);
            }
            cout<<endl;

        }
        
        void inorder(TreeNode* root)
        {
            TreeNode* cur = root;
            stack<TreeNode*> s;
            cout<<"The Inorder of the given tree : ";
            while(cur || !s.empty())
            {
                while(cur)
                {
                    s.push(cur);
                    cur = cur->left;
                }
                TreeNode* node = s.top();
                s.pop();
                cout<<node->val<<" ";
                cur=node->right;
            }
            cout<<endl;
        }

        void postorder(TreeNode* root)
        {
            stack<TreeNode*>s1,s2;
            s1.push(root);
            while(!s1.empty())
            {
                TreeNode* node = s1.top();
                s1.pop();
                s2.push(node);                              //s2.push(node) ->we are not using node->val because we are storing the value in pointer
                if(node->left) s1.push(node->left);
                if(node->right) s1.push(node->right);
            }
            cout<<"THe postourder of the given tree : ";
            while(!s2.empty())
            {
                cout<<s2.top()->val<<" ";   // if add s2.top to print then it print address so we should use s2.top->val;
                s2.pop();
            }
            cout<<endl;
        }

};
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    DFS d;
    d.preorder(root);
    d.inorder(root);
    d.postorder(root);


}