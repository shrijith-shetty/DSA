#include<iostream>
#include<vector>
using namespace std;

class BST{
    public:
    int data;
    BST* rchild;
    BST* lchild;

    BST(int value)
    {
        value = data;
        rchild = nullptr;
        lchild = nullptr;
    }
    
}l;

BST* create(BST* root, int value)
{
    if(!root)
        return new BST(value);
    
    if(root->data > value)
        root->lchild = create(root->lchild,value);
    else if(root->data < value) 
        root->rchild = create(root->rchild, value);
    return root;
}
int main()
{

}