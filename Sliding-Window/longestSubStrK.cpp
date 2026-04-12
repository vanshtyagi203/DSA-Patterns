/*
   Longest Substring with exact k distinct character
   Approach=>
   - Use sliding window (low, high)
   - Expand window by increasing 'high'
   - If distinct chars > k → shrink from 'low'
   - When distinct chars == k → update max length

   Input:
   aabacbebebe
   3
   Output:
   7   
   cbebebe -> 3 distinct chars
*/
#include<bits/stdc++.h>
using namespace std;
int longestSubstringK(string str,int k){
    int low=0,high=0;
    int res=0;

    unordered_map<char,int> mpp;

   for(int high=0;high<str.length();high++){
      mpp[str[high]]++;

      while(mpp.size()>k){
        mpp[str[low]]--;
        if(mpp[str[low]]==0){
            mpp.erase(str[low]);
        }
        low++;
      }

      if(mpp.size()==k){
        int len=high-low+1;
        res=max(res,len);
      }
   }
   return res;
}

int main(){
    string str;
    getline(cin,str);
    int k;
    cin>>k;
    int res=longestSubstringK(str,k);
    cout<<res<<endl;

 return 0;
}