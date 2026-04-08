//Given an array find max sum of any subarray of size k

#include<bits/stdc++.h>
using namespace std;
int maxSumSubArr(int n,int arr[],int k){
    int low=0;
    int high=k-1;
    
    int sum=0;
    int res=0;
    for(int i=low;i<=high;i++){
       sum=sum+arr[i];
    }
    
       while(high<n){
        res=max(res,sum);
        low++;
        high++;
        if(high==n){
            break;
        }
       sum=sum-arr[low-1];
       sum=sum+arr[high];
       }
    
    return res;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int k;
    cin>>k;

    int res=maxSumSubArr(n,arr,k);
    cout<<res<<endl;
    return 0;
}