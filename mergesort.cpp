#include<bits/stdc++.h>
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
void merge(vector<int>&arr, int low, int mid, int high){
  vector<int>temp;
  int left=low;
  int right=mid+1;
  while(left<=mid && right<=high){
    if(arr[left]<arr[right])
    {
        temp.push_back(arr[left]);
        left++;
    }
    else{
        temp.push_back(arr[right]);
        right++;
    }
  }
  while(left<=mid){
    temp.push_back(arr[left]);
    left++;
  }
  while(right<=high){
    temp.push_back(arr[right]);
    right++;
  }
  for(int i=low; i<=high; i++){
    arr[i]=temp[i-low];
    // cout<<arr[i]<<" ";
  }
  // cout<<endl;


}

void mergeSort(vector<int>&arr, int low, int high){
    if(high==low)
    return;
    int mid=(low+high)/2;
   mergeSort(arr,low,mid);
  
   mergeSort(arr,mid+1,high);

   cout<<"First Part"<<endl;

  for(int i=0; i<=mid; i++){
    cout<<arr[i]<<" ";
   }
   cout<<endl;

  cout<<"Second Part"<<endl;
   for(int i=mid+1; i<=high; i++){
    cout<<arr[i]<<" ";
   }
   cout<<endl;
   cout<<"After merge"<<endl;
   merge(arr, low, mid, high);
   
    
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
    mergeSort(arr, 0,n-1);
    cout<<"Sorted List is "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
// Time Complexity: O(n log n)
// Space Complexity: O(n log n)
