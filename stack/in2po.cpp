#include<iostream>
#include<string>
using namespace std;

class Stack{
  public:
    int size =50;
    int top = -1;
    char *stack;

    ~Stack() {
        delete[] stack; // Free allocated memory
    }

    Stack(){
        stack = new char[size];
    }

    char pop()
    {
        if(!isEmpty())
        {
        return stack[top--];
        }else {
            cout << "Stack Underflow\n";
            return '\0'; // Return null character if stack is empty
        } 
    }

    bool isFull()
    {
        return top == size-1;

    }
    void push( char x)
    {
        if (!isFull()) {
            stack[++top] = x;
        } else {
            cout << "Stack Overflow\n";
        }
        
    }

    bool isEmpty( )
    {
        return top==-1;
    }

    char peek()
    {
        if(!isEmpty())
        {
            return stack[top];
        }
        return '\0';
    }
};

class Infix2Postfix{

    public:

    Stack s;
    int precedence(char symbol)
    {
        if(symbol == '-' || symbol == '+')
            return 1;
        else if(symbol == '/' || symbol == '*')
            return 2;
        return 0;
    }

    bool isOperand(char character) {
        // Return true for alphanumeric characters (operands), false for operators
        return !(character == '+' || character == '*' || character == '/' || character == '-');
    }

    char *infixtopostfix(const char *infix)
    {
        int length = s.size;
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
                while (!s.isEmpty() && precedence(infix[i]) <= precedence(s.peek())) {
                    postfix[j++] = s.pop();
                }
                s.push(infix[i++]);
            }
        }
        while(!s.isEmpty())
        {
            postfix[j++] = s.pop();
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