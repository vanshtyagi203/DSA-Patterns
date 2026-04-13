//   Longest Substring with at most k distinct characters
// LeetCode == Fruits into Basket (number instead of char)
#include<bits/stdc++.h>
using namespace std;
int longestSubstringAtMostK(string str,int k){
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
        int len=high-low+1;
        res=max(res,len);
      
   }
   return res;
}

int main(){
    string str;
    getline(cin,str);
    int k;
    cin>>k;
    int res=longestSubstringAtMostK(str,k);
    cout<<res<<endl;

 return 0;
}