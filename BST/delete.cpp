#include <iostream>
#include <vector>
using namespace std;

class BST
{
public:
    int data;
    BST *rchild;
    BST *lchild;

    BST(int val)
    {
        data = val;
        rchild = nullptr;
        lchild = nullptr;
    }
};

BST* findme(BST* root)
{
    while(root && root->lchild)
    {
        root = root->lchild;
    }
    return root;
}

BST* delete_01(BST* root, int value)
{
    if(!root)  return nullptr;

    if(root->data>value)
        root->lchild = delete_01(root->lchild,value);
    else if(root->data < value)
        root->rchild = delete_01(root->rchild, value);
    else{
        if(!root->rchild)
        {
            BST* temp = root->lchild;
            delete root;
            return temp;
        }
        else if(!root->lchild){
            BST* temp = root->rchild;
            delete root;
            return temp;
        }

        BST* temp = findme(root->rchild);
        root->data = temp->data;
        root->rchild = delete_01(root->rchild, temp->data); 
    }
  return root; 
}

BST *insert(BST *root, int val)
{
    if (!root)
        return new BST(val);
    if (root->data > val)
        root->lchild = insert(root->lchild, val);
    else if (root->data < val)
        root->rchild = insert(root->rchild, val);

    return root;
}

void inorder(BST *root)
{
    if (!root)
        return;
    inorder(root->lchild);
    cout << root->data << " ";
    inorder(root->rchild);
}

BST* search(BST* root, int val)
{
    if(!root){
        cout<<"Not present\n"<<endl;    
        return root;
    }
    if(root->data>val)
    {
        root->lchild = search(root->lchild , val);
    }
    else if(root->data < val)
    {
        root->rchild = search(root->rchild, val);
    }
    if(val == root->data)
        cout<<"FOund the value "<<val<<endl;
    return root;

}

int main()
{
    BST* root = nullptr;
    BST* root1 = nullptr;
    vector<int> arr = {6,4,125,22,23,21,68,21,66};
    for(int val : arr)
    {
        root = insert(root,val);
    }

    cout<<"Inorder of the tree is \n";
    inorder(root);

    cout<<"search \n"<<endl;
    root1 = search(root,26);

    cout<<"delete 22\n";
    root = delete_01(root, 22);
    cout<<"Inorder of the tree is \n";
    inorder(root);

}


