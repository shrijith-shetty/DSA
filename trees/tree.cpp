#include<iostream>
using namespace std;

class Tree{
    public:
    int data;
    Tree *left, *right;

    Tree(int value)
    {
        data = value;
        left = right = nullptr;
    } 
};

Tree* insert(Tree* root, int value)
{
    if(root==nullptr)
    {
        return new Tree(value);
    }
    else{
        if(value<root->data)
        {
            root->left = insert(root->left,value);
        }
        else{
            root->right = insert(root->right,value);
        }
    }
    return root;
}

void inorder(Tree* root)
{
    if(root==nullptr) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Tree* root)
{
    if(root==nullptr) return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Tree* root)
{
    if(root==nullptr) return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    
}
int main() {
    Tree* root = nullptr;
    int n, value;

    cout << "Enter the number of elements to insert: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    return 0;
}