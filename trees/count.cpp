#include<iostream>
#include<stack>
using namespace std;

class Tree{
    public:
    int value;
    Tree* lchild;
    Tree* rchild;

    Tree(int x) : value(x) , lchild(NULL), rchild(NULL) {};
};

int count(Tree* root)
{
    int x, y;
    if(root!=NULL)
    {
        x = count(root->lchild);
        y = count(root->rchild);
        return x+y+1;
    }
    return 0;
}

int main()
{
    Tree* root = new Tree(1);
    root->lchild = new Tree(2);
    root->rchild = new Tree(3);
    root->lchild->lchild = new Tree(4);
    root->lchild->rchild = new Tree(5);
    root->rchild->lchild = new Tree(6);
    root->rchild->rchild  = new Tree(7);
    root->rchild->lchild->lchild = new Tree(8);
    root->rchild->lchild->rchild = new Tree(9);
    cout<<count(root)<<"\n";
}