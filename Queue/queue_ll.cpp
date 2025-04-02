// queueu using linked list 

#include<iostream>
using namespace std;

class LL{
    public:
    int data;
    LL * next;

    ~LL(){
        delete next;
    }
}*front = nullptr, *rear = nullptr;

class Solution:public LL{
    public:
    void enqueue(int x)
    {
        LL *t = new LL();
        t->data = x;
        t->next = nullptr;
        if(front == nullptr)
        {
            front= rear = t;
        }
        else{
            rear->next = t;
            rear = t;
        }
    }

    void display()
    {
        LL * t = front;
       do
        {
            cout<<t->data<<" ";
            t = t->next;
        } while(t!=nullptr);
        cout<<endl;
    }

    ~Solution() {
        LL *t = front;
        while (t != nullptr) {
            LL *temp = t;
            t = t->next;
            delete temp;
        }
    }
};

int main()
{
    Solution s;
    s.enqueue(10);
    s.enqueue(10);
    s.enqueue(10);
    s.enqueue(10);
    s.enqueue(10);
    s.enqueue(10);
    s.enqueue(10);
    s.display();

}