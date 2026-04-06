//                                          BETTER APPROACH
//Through hashing
// This approach fixes one element and uses hashing to find the other two elements.
// For each element, a set is used to check if the required third value already exists.
// Valid triplets are sorted and stored in a set to avoid duplicates.
// Finally, all unique triplets are collected and returned as the result.

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(int n,vector<int>&arr){
     
    vector<vector<int>> ans;
    set<vector<int>>uniqueTriplet;

    for(int i=0;i<n;i++){
        int target=-arr[i];
         
        set<int> s;
        for(int j=i+1;j<n;j++){
             int toFind=target-arr[j];

             if(s.find(toFind)!=s.end()){
                vector<int> triplet={arr[i],arr[j],toFind};
                sort(triplet.begin(),triplet.end());

                uniqueTriplet.insert(triplet);//storing unique triplet 
             }
             s.insert(arr[j]);
        }
    }
    for(auto it:uniqueTriplet){
        ans.push_back(it);
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



//-----------------------------------------------------------------------------------------------------------------------

//                                   BRUTE FORCE
//// This function finds all triplets in the array whose sum is 0.
// It uses three nested loops to check every possible combination of 3 elements.
// Each valid triplet is sorted and stored in a set to avoid duplicates.
// Unique triplets are then added to a vector and returned as the result.

// #include<bits/stdc++.h>
// using namespace std;
// vector<vector<int>> threeSum(int n,vector<int> &arr){
//      vector<vector<int>> ans;
//      set<vector<int>> s;

//      for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             for(int k=j+1;k<n;k++){
//                 if(arr[i]+arr[j]+arr[k]==0){
//                     vector<int> triplet={arr[i],arr[j],arr[k]};
//                      sort(triplet.begin(),triplet.end());

//                      if(s.find(triplet)==s.end()){
//                         s.insert(triplet);
//                         ans.push_back(triplet);
//                      }
//                 }
//             }
//         }
//      }
//      return ans;
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }

//     vector<vector<int>> res=threeSum(n,arr);
     
//     for(auto triplet:res){
//         for(auto it:triplet){
//             cout<<it<<" ";
//         }
//     }
//     return 0;
// }