#include<iostream>
#include<queue>
using namespace std;

class Level{
    public:
        int value;
        Level* left;
        Level* right;
         
        Level(int x) : value(x), left(NULL),right(NULL){};
};

void levelorder(Level* root)
{
    queue<Level*>q; 
    q.push(root);
    cout<<"The level order for the following tree : ";
    while(!q.empty())
    {
        Level* node = q.front();
        q.pop();
        cout<<node->value<<" ";
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
    cout<<endl;
}
int main()
{
    Level* root = new Level(1);
    root->left = new Level(2);
    root->right = new Level(3);
    root->left->left = new Level(4);
    root->left->right = new Level(5);
    root->right->left = new Level(6);
    root->right->right = new Level(7);
    levelorder(root);

}