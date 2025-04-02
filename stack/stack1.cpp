#include<iostream>
using namespace std;

class Stack{
    public:
        int size;
        int top;
        int *stack;

        ~Stack (){
            delete stack;
        }
};

class Operation{
    public:
        void create(Stack *st)
        {
            cout<<"Enter the value\n";
                cin>>st->size;
            st->top = -1;
            st->stack = new int[st->size];
        }

        void push(Stack *st, int value)
        {
            if(st->top == st->size-1)
            {
                cout<<"The stack is full\n";
                return ;
            }
            else{
                st->top++;
                st->stack[st->top] = value;
            }
        }

        int pop(Stack* st)
        {
            if(st->top == -1)
            {
                cout<<"The stack is underflow\n";
                return 0;
            }
            int x = st->stack[st->top--];
            return x;
        }

        void display(Stack st)
        {
            for(int i=0;i<st.top;i++)
            {
                cout<<st.stack[i]<<" ";
            }
            cout<<endl;
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