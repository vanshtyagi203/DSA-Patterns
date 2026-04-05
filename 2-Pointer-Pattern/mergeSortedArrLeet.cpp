//Merge Sorted Array Leetcode style

#include<bits/stdc++.h>
using namespace std;

void mergeSortedArr(int m,vector<int> &arr1,int n,vector<int> &arr2){
    int i=m-1;
    int j=n-1;
    int idx=m+n-1;

    while(i>=0 && j>=0){
        if(arr1[i]>=arr2[j]){
            arr1[idx]=arr1[i];
            i--;
            idx--;
        }
        else{
            arr1[idx]=arr2[j];
            j--;
            idx--;
        }
    }
    while(j>=0){
        arr1[idx]=arr2[j];
        idx--;
        j--;
    }
}

int main(){
    int m;
    cin>>m;

    int n;
    cin>>n;

    vector<int> arr1(m+n);
    for(int i=0;i<m;i++){
        cin>>arr1[i];
    }

    
    vector<int> arr2(n);
    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }

    mergeSortedArr(m,arr1,n,arr2);

    for(int i=0;i<(m+n);i++){
     cout<<arr1[i]<<" ";
    }
    return 0;

}