#include<iostream>
#include<math.h>
using namespace std;

void tower_of_hanoi(int n,char src,char supp,char des){
  if(n==1){
cout<<"move "<<n<<" from "<<src<<" to "<<des<<endl;
return;
}
 tower_of_hanoi(n-1,src,des,supp);
 cout<<"move "<<n<<" from "<<src<<" to "<<des<<endl;
 tower_of_hanoi(n-1,supp,src,des);
}
int main(){
    cout<<"Enter number of plates: ";
 int n;
cin>>n;
 tower_of_hanoi(n,'A','B','C'); cout<<"number of moves required: "<<pow(2,n)-1;
return 0;
}