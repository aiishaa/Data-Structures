#include <iostream>

using namespace std;

struct node{
    int data;
    node *next;
};

class Queue{
private:
    node* Front;
    node *Rear;
    int length;
public:
    Queue(){ Rear = Front = NULL; length = 0;}
    int getLength(){
        return length;
    }

    bool isEmpty(){
        return (Front == NULL);
    }

    void Enqueue(int value){
        node *newNode = new node;
        newNode->data = value;

        if(isEmpty()){
            Front = Rear = newNode;
            Front->next = Rear->next = NULL;
        }

        else{
            Rear->next = newNode;
            Rear = newNode;
            Rear->next = NULL;
        }

        length++;
    }

    void Dequeue(){
        if(isEmpty())
            return;

        node *ptr = Front;
        if(Front == Rear)
            Front = Rear = NULL;
        else
            Front = Front->next;

        ptr->next = NULL;
        delete ptr;
        length--;
    }

    node *getFront(){
        return Front;
    }

    node *getRear(){
        return Rear;
    }

    void print(){
        node *ptr = Front;
        while(ptr != NULL){
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }

};

class Stack{
private:
    Queue q;
public:
    Stack(){}
    void push(int value){
        int len = q.getLength();
        q.Enqueue(value);
        for (int i = 0; i < len; i++)
        {
            q.Enqueue(q.getFront()->data);
            q.Dequeue();
        }
    }

    int Top(){
        if(q.isEmpty()) return -1;
        return q.getFront()->data;
    }

    // Removes the top element
    void pop()
    {
        if (q.isEmpty())
            cout << "No elements\n";
        else
            q.Dequeue();
    }

    void print(){
        q.print();
    }
};
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << "After pushing 1, 2, 3 \n";
    cout << "our stack: \n";
    s.print();
    cout << "new top = " << s.Top() << endl;

    s.pop();
    cout << "\nAfter 1 popping \n";
    cout << "our stack: \n";
    s.print();
    cout << "new top = " << s.Top() << endl;

    s.push(4);
    s.push(5);
    cout << "\nAfter pushing 4, 5 \n";
    cout << "our stack: \n";
    s.print();
    cout << "new top = " << s.Top() << endl;

    s.pop();
    s.pop();
    cout << "\nAfter 2 popping \n";
    cout << "our stack: \n";
    s.print();
    cout << "new top = " << s.Top() << endl;
    return 0;
}
