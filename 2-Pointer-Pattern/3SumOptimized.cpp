#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(int n,vector<int>&arr){
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());

    for(int i=0;i<n;i++){
       if(i>0 && arr[i]==arr[i-1]){  //to skip the repeated values
        continue;
       }

        int j=i+1;
        int k=n-1;
       while(j<k){
        int sum=arr[i]+arr[j]+arr[k];

        if(sum>0){
            k--;
        }
        else if(sum<0){
         j++;
        }
        else{
            vector<int> triplet={arr[i],arr[j],arr[k]};
            ans.push_back(triplet);
            j++;
            k--;

            while(j<k && arr[j]==arr[j-1]){
                j++;
            }
            while(j<k && arr[k]==arr[k+1]){
                k--;
            }
        }

       }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<vector<int>> res=threeSum(n,arr);
     
    for(auto triplet:res){
        for(auto it:triplet){
            cout<<it<<" ";
        }
    }
    return 0;
}