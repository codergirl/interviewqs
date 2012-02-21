#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

template<typename T> class Quicksort
{
public:
    Quicksort(T* arr_, int size_) : arr(arr_), size(size_)
    { ; }

    void sort()
    {
        sort_(arr, 0, size-1);
    }
    
    void printarr()
    {
        int i;
        for(i=0; i<size; i++)
            cout << arr[i] << " ";
        cout << "\n\n";
    }

private:
    T* arr;
    int size;

    void sort_(T* arr, int start, int end)
    {
        if (end-start <= 0)
            return;

        int m = start;
        int i;
        for(i=start+1; i<=end; i++)
        {
            if (arr[i] < arr[start])
            {
                swap(arr, ++m, i);
            }
        }
        swap(arr, start, m);

        sort_(arr, start, m-1);
        sort_(arr, m+1, end);
    }

    void swap(T arr[], int i, int j)
    {
        T temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
};


int main(int argc, char* argv[])
{
    int arr[] = {12, 19, 3, 8, 22, 2, 320, 6};
    int size = sizeof(arr)/sizeof(int);

    Quicksort<int> sorter(arr, size);
    sorter.printarr();
    sorter.sort();
    sorter.printarr();
}

