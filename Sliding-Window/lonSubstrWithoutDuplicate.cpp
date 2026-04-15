/*
Longest Substring without duplicate character
input = {dabcaba}
output= 4 (dabc)
*/
#include<bits/stdc++.h>
using namespace std;
int longestSubstrWDuplicate(string str){
    
    unordered_map<char,int>mpp;

    int low=0,high=0;
    int res=-1;
    
    for(int high=0;high<str.length();high++){
         mpp[str[high]]++;
         int k=high-low+1;

         while(mpp.size()<k){
            mpp[str[low]]--;
            if(mpp[str[low]]==0){
                mpp.erase(str[low]);
            }
            low++;
            k=high-low+1;
         }
         int len=high-low+1;
         res=max(res,len);
    }
    return res;
}
int main(){
    string str;
    getline(cin,str);

    int res=longestSubstrWDuplicate(str);
    cout<<res<<endl;
    return 0;
}