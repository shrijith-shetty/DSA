// circular queue using array

#include<iostream>

using namespace std;

class Queue{
    public:
    int size;
    int front;
    int rear;
    int *Q;

    Queue()
    {
        size = 10;
        front = rear = -1;
       
        Q = new int[size];
    }

    ~Queue(){
        delete[] Q; 
    }
};

class Circular : public Queue{
    public:
    void enqueue(int x)
    {
        if((rear+1)%size == front)
        {
            cout<<"Q is overflow"<<endl;
        }
        else{
            rear = (rear+1)%size;
            Q[rear] = x;
        }
    }

    void dequeue()
    {
        if(front== rear)
        {
            cout<<"Q is empty\n";
            return ;
        }
        else
        {
            front = (front+1)%size;
            cout<<"The deleted value is :"<<Q[front]<<endl;   
        }
    }

    void display()
    {
        cout<<"The value are : ";
        int i=front+1;
        do{ 
            cout<<Q[i]<<" ";
            i = (i+1)%size;
        }while(i!=(rear+1)%size);
         cout<<endl;
    }
};

int main()
{
    Circular c;
    c.enqueue(10);
    c.enqueue(20);
    c.enqueue(30);
    c.enqueue(40);
    c.enqueue(50);
    c.display();

    c.dequeue();
    c.dequeue();
    c.display();

    c.enqueue(60);
    c.enqueue(70);
    c.display();
}