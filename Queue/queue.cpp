// Implementing queue usign arrray :

#include<iostream>

using namespace std;

class Queue{
    public:
    int size=10;
    int front;
    int rear;
    int *array;
    
    Queue(int s = 10)
    {
        size = s;
        front = -1;
        rear = -1;
        array = new int[size];
    }
    void enqueue(int x)
    {
        if(rear == size-1)
        {
            cout<<"Overflow\n";
            return;
        }
        else{
            rear++;
            array[rear] = x;
        }
    }

    int dequeue(){
        int x= -1;
        if(rear == front)
        {
            cout<<"Under flow"<<endl;
            return x;
        }
        else{
            cout<<"The deleted value is : "; 
            front++;
            return x = array[front];
        }
        return x;
    }

    void display()
    {
        cout<< " The value are\n";
        for(int i=front+1;i<rear;i++)
        {
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }

    ~Queue()
    {
        delete[] array;
    }
};

int main()
{
    Queue q;
    while(1)
    {
        int n;
        cout<<endl<<"Enter 1 to insertion\n2 to deletion \n";
            cin>> n;

        switch(n)
        {
            case 1 :
                int x;
                cout<<"Enter the value\n";
                cin>>x;    
                q.enqueue(x);
                break;

            case 2 :
                int m;
                m= q.dequeue();
                cout<<m<<endl;
                break;
            case 3:
                q.display();
                break;

            default:
                cout<<"Closed\n";
                
            return 0;
        }
    }
}