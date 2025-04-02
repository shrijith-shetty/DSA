#include<iostream>
using namespace std;

class Stack{
public:
    int data;
    Stack *next;

    ~Stack(){
        delete next;
    }
};


class StackLL{
    public:
    void create(Stack **st)
    {
        int size;
        cout<<"Enter the size of hte array \n";
            cin>>size;
        for(int i=0;i<size;i++){
            cout<<"Enter the values\n";
            Stack *t = new Stack();
                cin>>t->data;
            t->next = *st;
            *st = t;
            
        }
    }

    void pop(Stack **st)
    {
        if(!*st)
        {
            cout<<"Stack is Empty"<<endl;
            return; 
        }
        else{
            Stack* head = *st;
            *st = (*st)->next;
            int data = head->data;
            cout<<data<<endl;
            head->next = nullptr;
            delete st;
        }   
    }

    void display(Stack *st)
    {
        while(st)
        {
            cout<<st->data<<" ";
            st = st->next;
        }
        cout<<endl;
    }
    void push(Stack *st)
    {
        Stack *t = new Stack;
        cout<<"Enter the value to be pushed\n";
            cin>>t->data;
        t->next = st;
        st = t;
    }
};
int main(){
    Stack *st = nullptr;
    StackLL sll;
    sll.create(&st);
    sll.display(st);
    sll.pop(&st);
    sll.pop(&st);
    sll.pop(&st);
    sll.display(st);
}