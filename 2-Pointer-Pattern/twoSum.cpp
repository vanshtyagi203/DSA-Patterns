//                                                      TWO POINTER APPROACH WITH TC=O(nlogn)
//                            This approach can be used when we have to return values not indexes as after sorting original index can be changed
#include<bits/stdc++.h>
using namespace std;

pair<int,int> twoSum(int arr[],int n,int target){
      sort(arr,arr+n);
      int i=0;
      int j=n-1;

      while(i<j){
        int sum=arr[i]+arr[j];
        if(sum==target){
            return {arr[i],arr[j]};
        }
        else if(sum>target){
            j--;
        }
        else if(sum<target){
            i++;
        }
        
      }
      return {-1,-1};
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;

    pair<int ,int> res=twoSum(arr,n,target);
    cout<<res.first<<" "<<res.second;
    return 0;
}

//------------------------------------------------------------------------------------------------------------------------------------------
//                                                   OPTIMAL SOLUTION WITH TC=O(N) AND SC=O(N)
//                                           This approach is used when we have to return the indexes not values                                                    
  //IN THIS WE ARE USING unordered_map 
  //  Check if (target - arr[i]) exists in map; if yes return indices, else store in map (  mpp[arr[i]]=i )
// #include<bits/stdc++.h>
// using namespace std;

// pair<int,int> twoSum(int arr[],int n,int target){
//     unordered_map<int,int> mpp;
//     for(int i=0;i<n;i++){
//         int t=target-arr[i];

//         if(mpp.find(t)!=mpp.end()){
//             return {mpp[t],i};
//         }
//         mpp[arr[i]]=i;
//     }
//     return{-1,-1};
// }

// int main(){
//     int n;
//     cin>>n;

//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int target;
//     cin>>target;

//     pair<int,int> res=twoSum(arr,n,target);
//     cout<<res.first<<" "<<res.second;
//     return 0;
// }


//--------------------------------------------------------------------------------------------------------
                                                  //BRUTE FORCE METHOD WITH TC=O(N^2)

// pair<int,int> twoSum(int arr[],int n,int t){
//      for(int i=0;i<n;i++){
//           int target=t-arr[i];

//         for(int j=i+1;j<n;j++){
            
//            if(arr[j]==target){
//              return {i,j};
//            }
//         }
//      }
//      return {-1,-1};
// }
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }

//     int t;
//     cin>>t;

//     pair<int,int> res=twoSum(arr,n,t);
//     cout<<res.first<<" "<<res.second;
//     return 0;
// }