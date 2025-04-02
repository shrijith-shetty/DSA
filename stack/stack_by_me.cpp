#include<iostream>
using namespace std;

class Stack{
    public:
    int size;
    int top;
    int *s;

    ~Stack(){
        delete [] s;
    }
};

class StackOperationP{
    public:
    void create(Stack* st){
        cout<<"Enter the size of the stack :"<<endl;
            cin>>st->size;
        st->top=-1;
        st->s=new int[st->size];   
    }

    void display(Stack* st)
    {
        for(int i=st->top;i>=0;i--)
        {   
            cout<<st->s[i]<<" ";
        }
        cout<<endl;
    }

    void push(Stack* st, int value)
    {
        if(st->top == st->size-1)
        {
            cout<<"Stack is overflow\n";
          
        }
        else{
            st->top++;
            st->s[st->top]=value;
        }
        
    }

    void pop(Stack* st)
    {
        if(st->top==-1)
        {
            cout<<"Stack is underflow\n";
            return;
        }
        st->top--;
    }
    
    int peek(Stack* st, int pos)
    {
        if(st->top-pos+1<0)
        {
            cout<<"Invalid positon\n";
            return -1;
        }
        return st->s[st->top-pos+1];
    }
};
int main()
{
    Stack st; // Create a stack instance
    StackOperationP c; // Create an instance of Create to operate on the stack
    c.create(&st); // Initialize the stack
    cout<<"created"<<endl;
    c.push(&st, 10); // Push element 10 onto the stack
    c.push(&st, 20); // Push element 20 onto the stack
    cout << c.peek(&st, 1) << endl; // Peek at the top element
    c.display(&st); // Display the stack elements
    return 0; 
}