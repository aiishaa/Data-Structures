#include <iostream>
using namespace std;

const int Max_Size = 1000;

class Queue{
private:
    int Elements[Max_Size];
    int Front, Rear;
public:
    Queue(){ Rear = Front = 0;}

    int getLength(){
        return Rear;
    }

    bool isEmpty(){
        return (Rear == 0);
    }

    void Enqueue(int value){
        if(Max_Size == Rear){ cout << "Queue is full" << endl;  return; }
        else{
            Elements[Rear] = value;
            Rear++;
        }
    }

    void Dequeue(){
        if(Front == Rear){
            cout << "The queue is empty" << endl;
            return;
        }
        for(int i = 0; i < Rear; i++){
            Elements[i] = Elements[i + 1];
        }
        Rear--;
    }

    void print(){
        if (Front == Rear) {
            cout << "Queue is Empty" << endl;
            return;
        }
        for (int i = Front; i < Rear; i++) {
            cout << Elements[i] << " ";
        }
        cout << endl;
    }

    int GetFront()
    {
        if (Front == Rear) {
            return -1;
        }
        return Elements[Front];
    }
};

class Time {
private:
    int time = 0;
public:
    Time(){}
    int CalculateTime(int arr[], int length, int k) {
        Queue q;
        for(int i = 0; i < length; i++){
            q.Enqueue(arr[i]);
        }
        int _front = 0;
        int i = 0;
        while(arr[k] != 0){
            _front = q.GetFront();
            if(_front != 0){
                _front--;
                time++;
                q.Enqueue(_front);
                q.Dequeue();
                arr[i % length]--;
            }
            else{
                q.Enqueue(_front);
                q.Dequeue();
            }
            i++;
        }
        return time;
    }
};

int main()
{
    cout << "Test case 1 \n";
    int arr1[2] = {1,2};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    Time t1;
    cout << t1.CalculateTime(arr1, n, 0) << endl;

    cout << "----------------------------------\n";
    cout << "Test case 2 \n";
    int arr2[3] = {2,3,2};
    n = sizeof(arr2)/sizeof(arr2[0]);
    Time t2;
    cout << t2.CalculateTime(arr2, n, 2) << endl;

    cout << "----------------------------------\n";
    cout << "Test case 3 \n";
    int arr3[4] = {5,1,1,1};
    n = sizeof(arr3)/sizeof(arr3[0]);
    Time t3;
    cout << t3.CalculateTime(arr3, n, 0) << endl;

    cout << "----------------------------------\n";
    cout << "Test case 4 \n";
    int arr4[2] = {1,2};
    n = sizeof(arr4)/sizeof(arr4[0]);
    Time t4;
    cout << t4.CalculateTime(arr4, n, 1) << endl;

    cout << "----------------------------------\n";
    cout << "Test case 5 \n";
    int arr5[8] = {2,2,1,4,5,6,7,2};
    n = sizeof(arr5)/sizeof(arr5[0]);
    Time t5;
    cout << t5.CalculateTime(arr5, n, 3) << endl;

    cout << "----------------------------------\n";
    cout << "Test case 6 \n";
    int arr6[11] = {83,86,38,31,59,25,89,71,54,71,84};
    n = sizeof(arr6)/sizeof(arr6[0]);
    Time t6;
    cout << t6.CalculateTime(arr6, n, 1) << endl;

    return 0;
}
