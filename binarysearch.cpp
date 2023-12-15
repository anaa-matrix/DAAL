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
int binarySearch(std::vector<int> arr, int n, int key) {
  int s = 0; // index of first element
  int e = n; // index of last element
  while (s <= e) {
    int mid = (s + e) / 2;
    std::cout << "Middle Element: " << arr[mid] << std::endl;
    if (arr[mid] == key) {
      // Print the middle element
 return mid;
    } else if (arr[mid] > key) {
      e = mid - 1;
    } else {
      s = mid + 1;
    }
  }
  return -1;
}
int main(){
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
 
  
  if(binarySearch(arr,n-1, target)!=-1)
  cout<<"Element is at index "<<binarySearch(arr, n-1,target)<<endl;
  else
  cout<<"Element not found"<<endl;
}

//O(log n)
