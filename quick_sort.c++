#include <iostream>
#include <random>
#include <vector>
using namespace std;
int stepCount = 1; // Global step counter
// Function to partition the array and return the pivot index
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low]; // Choose the first element as the pivot
    int i = low;
    // Index of the smaller element
    for (int j = low + 1; j <= high; j++)

    {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot)

        {
            i++; // Increment index of the smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i], arr[low]);
    return i;
}
// Function to perform Quick Sort
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)

    {
        // Partition the array and get the pivot index
        int pivotIndex = partition(arr, low, high);
        // Print the current pivot selection step
        cout << "Step " << stepCount++ << ": Selected pivot: " << arr[pivotIndex] << endl;
        // Print the current state of the array after partitioning
        cout << "Step " << stepCount++ << ": ";
        for (int i = low; i <= high; i++)

        {
            cout << arr[i] << " ";
        }
        cout << endl;
        // Recursively sort the subarrays before and after the pivot
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(1, 100);
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        arr[i] = distribution(gen);
    }

    // cout << "Enter " << n << " elements: ";
    // for (int i = 0; i < n; i++)
    // {
    //   cin >> arr[i];
    // }
    cout << "Original Array: ";
    for (int num : arr)

    {
        cout << num << " ";
    }
    cout << endl;
    quickSort(arr, 0, n - 1);
    cout << "Sorted Array: ";
    for (int num : arr)

    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
