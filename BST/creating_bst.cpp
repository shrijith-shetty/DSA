#include <iostream>
#include<vector>
using namespace std;

class Bst
{
public:
    int data;
    Bst *lchild;
    Bst *rchild;

    void create(Bst* &root, int value)
    {
        if (!root)
        {
            root->data = value;
            root->lchild = nullptr;
            root->rchild = nullptr;
        }
        Bst *t = root;
        while (!t)
        {
            if (value > t->data)
            {
                t = t->rchild;
            }
            else if (value < t->data)
            {
                t = t->lchild;
            }
            else
                return;
        }
        Bst *val = nullptr;
        val->data = value;
        val->lchild = nullptr;
        val->rchild = nullptr;

        if (t->data > value)
            t->lchild = val;
        else
            t->rchild = val;

        root = t;
    }

    void display(Bst* root)
    {
        display(root->lchild);
        cout<<root->data;
        display(root->rchild);
    }
};
int main()
{
    Bst* root = nullptr;
    vector<int> arr = {5,4,6,1,6,7,15,72,72,82};
    for(auto val : arr)
    {
        root->create(root,val);
    }
    root->display(root);
}