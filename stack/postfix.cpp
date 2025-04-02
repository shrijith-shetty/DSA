#include<iostream>
using namespace std;
class Stack{
    public:
    int size ;
    int top;
    char *stack[]; 

    ~Stack(){
        delete[] stack;
    }
}; 

bool isempty(){

}

bool isOperand(char a)
{
    if(a == '+' || a == '*'|| a =='/' || a == '-')
    {
        return 0;
    }
    return 1;
}

int greater(char a)
{   
    if(a == '+' || a == '-' )
        return 1;
    else if(a == '/' || a == '*' )
        return 2;
    return 0;
}

char pop(Stack * st)
{
    if(st -> top == -1 )
    {
        cout<<"The stack is full\n";
        return 0;
    }
    else{
        char charecter = st->stack[st->top];
        st->stack[st->top--];
    }
    return charecter;
}
char *InToPost(char **infix)
{
    Stack * st;
    int i=0,j=0;
    st->size = 50;
    char prefix[st->size];
    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
        {
            prefix[j++] = infix[i++];
            
        }
        else{
            if(greater(infix[i]),greater(st->stack[st->top])))
            {
                    st->stack[j++] = infix[i++];
            }
            else{
                postfix[j++] = pop(&stack);
            }
        }
    }

    while(isempty(st->stack[++j])
    {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0';

    return 0;
};

int main() {
    char infix[] = "a+b*c";
    char *postfix = InToPost(&infix);
    cout << "Postfix: " << postfix << endl;
    delete[] postfix; // Free allocated memory
    return 0;
}