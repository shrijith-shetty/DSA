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

int count_(Tree* root)
{
    //counting the node which has two child 
    int x, y;
    if(root!=NULL)
    {
        x = count(root->lchild);
        y = count(root->rchild);
        if(root->rchild && root->lchild)
           return x+y+1;
        else
            return x+y;
    }
    return 0;
}

int total_value(Tree* root)
{
    int x=0,y=0;
    if(root!=NULL)
    {
        x = total_value(root->lchild);
        y = total_value(root->rchild);
        return x+y+root->value;
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
    root->rchild->rchild->lchild = new Tree(8);
    root->rchild->lchild->rchild = new Tree(9);
    cout<<" Total number of child : ";
    cout<<count(root)<<"\n";
    cout<<" Tree which has two child : ";
    cout<<count_(root)<<"\n";
    cout<<" Sum of all values : ";
    cout<<total_value(root)<<"\n";


}