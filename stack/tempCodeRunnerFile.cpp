#include<iostream>
#include<string>
using namespace std;

class Stack{
  public:
    int size =50;
    int top = -1;
    char *stack;

    ~stack(){
        delete[] stack;
    }
};

class Infix2Postfix{

    public:

    int precedence(char symbol)
    {
        if(symbol == '-' || symbol == '+')
            return 1;
        else if(symbol == '/' || symbol == '*')
            return 2;

        return 0;
    }

    bool isOperand(char charecter)
    {
        if(charecter == '+' || charecter == '*'|| charecter == '/'|| charecter == '-')
            return 0;
        return 1;
    }

    char pop()
    {
        Stack *st;
        if(!isEmpty())
        {
        return st->stack[st->top--];
        }else {
            cout << "Stack Underflow\n";
            return '\0'; // Return null character if stack is empty
        } 
    }

    bool isFull()
    {
        Stack *st;
        return st->top == st->size-1;

    }
    char push(Stack &st, char x)
    {
        if (!isFull()) {
            st.stack[++st.top] = x;
        } else {
            cout << "Stack Overflow\n";
        }
        
    }

    bool isEmpty( )
    {
        Stack *st;
        return st->top==-1;
    }

    char *infixtopostfix(const char *infix)
    {
        Stack st;
        int length = strlen(infix);
        char *postfix = new char[length+1];
        int i = 0;
        int j = 0;
        while(infix[i] != '\0')
        {
            if(isOperand(infix[i]))
            {
                postfix[j++] = infix[i++];
            }
            else
            {
                if(precedence(infix[i])>precedence(st.stack[st.top]))
                {
                    push(st, infix[i++]);
                }
                else
                {
                    postfix[j++]=pop();
                }
            }
        }
        while(!isEmpty())
        {
            postfix[j++] = pop();
        }
        postfix[j] = '\0';
        return postfix;
    }
};

int main() {
    Infix2Postfix i;
    const char* infix = "a+b*c";
    char *postfix = i.infixtopostfix(infix);
    cout << "Postfix: " << postfix << endl;
    delete[] postfix; // Free allocated memory
    return 0;
}