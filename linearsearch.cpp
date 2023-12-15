#include <iostream>
#include <vector>
#include <random>
#include <bits/stdc++.h>
using namespace std;
vector<int> generate_unique_random_elements(int n, int start, int end) {
  vector<int> elements;
  for (int i = start; i <= end; ++i) {
    elements.push_back(i);
  }

  random_device rd;
  mt19937 g(rd());
  shuffle(elements.begin(), elements.end(), g);

  elements.resize(n);
  return elements;
}

void linear_search_with_steps(vector<int> arr, int key) {
  bool found = false;

  for (int i = 0; i < arr.size(); i++) {
    cout << "Checking element at index " << i << " which is " << arr[i] << endl;

    if (arr[i] == key) {
      cout << "Key is found at index " << i << endl;
      found = true;
      break;
    }
  }

  if (!found) {
    cout << "Key is not found" << endl;

  }
}

int main() {
  int n;
  cout<<"Enter the number of elements in array"<<endl;
  cin>>n;
 
 vector<int>arr=generate_unique_random_elements(n,1,n);
  
  
  cout<<"Elements of array are: "<<endl;
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  sort(arr.begin(), arr.end());
  cout<<"Sorted array is"<<endl;
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  cout<<"Enter the target"<<endl;
  int target;
  cin>>target;
 

  cout << "Searching for key = " << target<< " in the array:" << endl;
  linear_search_with_steps(arr, target);
  return 0;
}