#include<iostream>
using namespace std;


class Stack{
    public:
    int size;
    int top;
    int *stack;

    ~Stack(){
      delete stack;  
    }
};

class Operation{
    public:

    void create(Stack *s)
    {
        cout<<"Enter the size \n";
            cin>>s->size;
        s->top = -1;
        s->stack = new int[s->size];
    }

    void push(Stack *st, int x)
    {
        if(st->top == st->size-1)
        {
            cout<<"Stack is overflow"<<endl;
            return ;
        }
        else{
            st->top++;
            st->stack[st->top] = x;
        }
    }

    int pop(Stack *st)
    {
        int x = -1;
        if(st->top == -1)
        {
            cout<<"Stack is underflow\n";
            return -1;
        }
        
        else{
             x = st->stack[st->top--];
        }
        return x;
    }

    void display(Stack st)
    {
        for(int i=st.top;i>=0;i--)
        {
            cout<<st.stack[i]<<" ";
        }
    }

};
int main()
{
    Stack st; // Create a stack instance
    Operation c; // Create an instance of Create to operate on the stack
    c.create(&st); // Initialize the stack
    c.push(&st, 10); // Push element 10 onto the stack
    c.push(&st, 20); // Push element 20 onto the stack
    c.pop(&st);
    c.pop(&st);
    c.pop(&st);

    //cout << c.peek(st, 1) << endl; // Peek at the top element
    c.display(st); // Display the stack elements
    return 0;
}