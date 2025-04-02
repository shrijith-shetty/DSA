#include<iostream>
using namespace std;

// Definition of the Stack class
class Stack {
public:
    int size; // Size of the stack
    int top;  // Index of the top element in the stack
    int *s;   // Pointer to dynamically allocated array for stack elements
};

// Definition of the Create class which contains methods to operate on the Stack
class Create {
public:
    Stack s; // An instance of Stack (not necessary, can be removed)

    // Method to create a stack with a specified size
    void create(Stack *stack) {
        cout << "Enter size" << endl;
        cin >> stack->size; // Input the size of the stack
        stack->top = -1;    // Initialize top to -1 indicating the stack is empty
        stack->s = new int[stack->size]; // Allocate memory for the stack array
    }

    // Method to display the elements of the stack
    void display(Stack st) {
        for (int i = st.top; i >= 0; i--) {
            cout << st.s[i] << " "; // Print each element from top to bottom
        }
        cout << endl;
    }

    // Method to push an element onto the stack
    void push(Stack *st, int x) {
        if (st->top == st->size - 1)
            cout << "Stack overflow" << endl; // Check for stack overflow
        else {
            st->top++;          // Increment top
            st->s[st->top] = x; // Add the element to the stack
        }
    }

    // Method to pop an element from the stack
    int pop(Stack *st) {
        int x = -1;
        if (st->top == -1) {
            cout << "Stack underflow" << endl; // Check for stack underflow
        } else {
            x = st->s[st->top--]; // Remove the top element and decrement top
        }
        return x; // Return the popped element
    }

    // Method to peek at an element at a specific position from the top
    int peek(Stack st, int pos) {
        if (pos <= 0 || pos > st.top + 1) {
            cout << "Invalid position" << endl; // Check for invalid position
            return -1;
        }
        return st.s[st.top - pos + 1]; // Return the element at the specified position
    }
};

// Main function to demonstrate stack operations
int main() {
    Stack st; // Create a stack instance
    Create c; // Create an instance of Create to operate on the stack
    c.create(&st); // Initialize the stack
    c.push(&st, 10); // Push element 10 onto the stack
    c.push(&st, 20); // Push element 20 onto the stack

    cout << c.peek(st, 1) << endl; // Peek at the top element
    c.display(st); // Display the stack elements
    return 0;
}