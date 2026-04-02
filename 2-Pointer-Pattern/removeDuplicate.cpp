#include<bits/stdc++.h>
using namespace std;

int removeDuplicate(int arr[],int n){

     if(n==0){
            return 0;
        }

      int i=0;
      int j=1;
      int unique=1;
     
      while(j<n){

        if(arr[i]==arr[j]){
            j++;
            continue;
        }
        else{
            arr[i+1]=arr[j];
            i++;
            j++;
            unique++;
        }
      }
      return unique;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   int res= removeDuplicate(arr,n);
   cout<<res<<endl;
    return 0;
}