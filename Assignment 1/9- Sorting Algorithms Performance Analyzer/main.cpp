#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <chrono>
#include <map>
#include <time.h>
using namespace std;

enum type{random_sorted, reverse_sorted};

class Sorter{
    public:
        virtual int *sort(int arr[], int n) = 0;
};

class SelectionSorter: public Sorter{
private:
public:
    SelectionSorter(){}
    int *SelectionSort(int arr[], int n){
        for(int i = 0; i < n-1; i++){
            int least = i;
            for(int j = i+1; j < n; j++){
                if(arr[j] < arr[least]){
                    least = j;
                }
            }
            swap(arr[least], arr[i]);
        }
        return arr;
    }

    int *sort(int arr[], int n){
        return SelectionSort(arr, n);
    }
};

class QuickSorter: public Sorter{
private:
public:
    QuickSort(){}
    int Partition(int arr[], int l, int r){
    int pivot = arr[l];
    int i = l, j = r;
    while(i < j){
        do{
            i++;
        }while(pivot >= arr[i]);

        do{
            j--;
        }while(pivot < arr[j]);
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[l], arr[j]);
    return j;
    }

    int *QuickSort(int arr[], int l, int r){
        if(l < r){
            int par = Partition(arr, l, r);
            QuickSort(arr, l, par);
            QuickSort(arr, par+1, r);
        }
        return arr;
    }
    int *sort(int arr[], int n){
        return QuickSort(arr, 0, n);
    }

};

class testbed{
private:
    Sorter *sorter;
public:
    int *GenerateRandomList(int min, int max, int size){
        int *arr = new int[size];
        // set seed to time(0)
        srand(time(0));
        for(int i = 0; i < size; i++){
            arr[i] = (rand() % max + min);
        }
        return &arr[0];
    }

    int *GenerateReverseOrderedList(int min, int max, int size){
        int *generatedlist = GenerateRandomList(min, max, size);
        // After sorting in reversed order
        sort(generatedlist, generatedlist + size, greater<int>());
        return &generatedlist[0];
    }

    double RunOnce(Sorter *sorter, int data[], int size){
        auto start = chrono::steady_clock::now();
        int * sorted = sorter->sort(data, size);
        auto end = chrono::steady_clock::now();
        return chrono::duration_cast<chrono::microseconds>(end - start).count();
    }

    double RunAndAverage(Sorter *sorter, int type, int min, int max, int size, int sets_num) {
        double TimeSum = 0.0;
        for(int  i = 0; i < sets_num; i++){
                if(type == type::random_sorted){
                    int *rand = GenerateRandomList(min, max, size);
                    TimeSum += RunOnce(sorter, rand, size);
                }
                else if(type == type::reverse_sorted){
                    int *rand = GenerateReverseOrderedList(min, max, size);
                    TimeSum += RunOnce(sorter, rand, size);
                }
        }
        return TimeSum/sets_num;
    }

    map<int, double> RunExperient (Sorter *sorter, int type, int min, int max, int min_val, int max_val, int sets_num, int step){
        double TimeAverage = RunAndAverage(&(*sorter), type, min, max, min_val, sets_num);
        map<int, double> Averages;
        for(int i = min_val + step; i <= max_val; i+=step){
            Averages.insert({i, RunAndAverage(&(*sorter), type, min, max, i, sets_num)});
        }
        return Averages;
    }
};
int main()
{
    testbed test;
    Sorter *sorter;
    // Run Experient tracer
    int option;
    while(true){
        cout << "Enter 1 for SelectionSort, 2 for Quick sort.\n";
        cin >> option;
        if(option == 1)
            sorter = new SelectionSorter();

        else if(option == 2)
            sorter = new QuickSorter();

        cout << "Sorting random data. Time elapsed in microseconds.\n";
        map<int, double> Averages_with_random_sorted = test.RunExperient(sorter, type::random_sorted, 1, 1100000, 0, 10000, 10, 5000);
        cout << "A_size  Time elapsed in micros" << endl;
        for (auto itr = Averages_with_random_sorted.begin(); itr != Averages_with_random_sorted.end(); ++itr) {
            cout << itr->first << '\t' << itr->second << '\n';
        }

        cout << "Sorting reverse ordered data. Time elapsed in microseconds.\n";
        map<int, double> Averages_with_reversed_sorted = test.RunExperient(sorter, type::reverse_sorted, 1, 1100000, 0, 10000, 10, 5000);
        cout << "A_size  Time elapsed in micros" << endl;
        for (auto itr = Averages_with_reversed_sorted.begin(); itr != Averages_with_reversed_sorted.end(); ++itr) {
            cout << itr->first << '\t' << itr->second << '\n';
        }
    }
    return 0;
}
