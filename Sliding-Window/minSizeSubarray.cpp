/*
 Minimum Size Subarray Sum
 
Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
*/
#include<bits/stdc++.h>
using namespace std;

int minSizeSubArr(int n,int arr[],int tar){
      int  low=0;
      int high=0;
      int sum=0;
      int res=INT_MAX;

    while(high<n){
    
      sum=sum+arr[high];
      while(sum>=tar){
        int len=high-low+1;
        res=min(res,len);
        sum=sum-arr[low];
        low++;
      }
      high++;  
    }

    if(res==INT_MAX){
        return 0;
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

    int tar;
    cin>>tar;

    int res=minSizeSubArr(n,arr,tar);
    cout<<res<<endl;
    return 0;
}