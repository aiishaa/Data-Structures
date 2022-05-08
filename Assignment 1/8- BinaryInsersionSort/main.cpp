#include <iostream>
#include <chrono>
using namespace std;

void insertionSort(long int arr[], int n){
    for(int i = 1; i < n; i++){
        int temp = arr[i];
        int j = i;
        for(; j > 0 && arr[j-1] > temp; j--){
            arr[j] = arr[j-1];
        }
        arr[j] = temp;
    }
}

int BinarySearch(long int arr[], int key, int low, int high){
    if (high <= low)
        return (key > arr[low]) ?
                (low + 1) : low;

    int mid = (low + high)/2;
    if(key == arr[mid])     return mid+1;
    else if(arr[mid] > key)     return BinarySearch(arr, key, low, mid - 1);
    else    return BinarySearch(arr, key, mid + 1, high);
}

void BinaryInsertionSort(long int arr[], int n){
    int i ,j;
    for(int i = 1; i < n; i++){
        int temp = arr[i];
        j = i - 1;
        int pos = BinarySearch(arr, temp, 0, j);

        while (j >= pos){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl << endl;
}


int main()
{
    long int n = 10000;
    int it = 0;
    double tim1[50], tim2[50];

    printf("A_size, linear insertion sort, Binary insertion sort\n");

    // Performs 10 iterations
    while (it++ < 10) {
        long int a[n], b[n];
        for (int i = 0; i < n; i++) {
            int no = rand() % n + 1;
            a[i] = no;
            b[i] = no;
        }
        clock_t start, end;

        // Linear insertion sort
        start = clock();
        insertionSort(a, n);
        end = clock();

        tim1[it] = ((double)(end - start));

        // Binary insertion sort
        start = clock();
        BinaryInsertionSort(b, n);
        end = clock();

        tim2[it] = ((double)(end - start));

        cout << n << "  " << (long int)tim1[it] << "  " << (long int)tim2[it] << endl;

        // increases the size of array by 10000
        n += 10000;
    }
    return 0;
}
