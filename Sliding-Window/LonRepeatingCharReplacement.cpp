/*
 Longest Repeating Character Replacement
 */
#include<bits/stdc++.h>
using namespace std;
int lonSubstrSameChar(string str,int k){
    int hash[256]={0};
    int low=0;
    int res=0;
    int maxFreq=0;
   
    for(int high=0;high<str.length();high++){
        hash[str[high]]++;
        maxFreq=max(maxFreq,hash[str[high]]);
        int totLen=high-low+1;
        while(  (totLen-maxFreq) > k){
            hash[str[low]]--;
            low++;
            totLen=high-low+1; //update
        }

        if( (totLen-maxFreq)<=k){
            res=max(totLen,res);
        }
    }
    
    return res;
} 
int main(){
    string str;
    getline(cin,str);
    int k;
    cin>>k;
    int res=lonSubstrSameChar(str,k);
    cout<<res<<endl;
    return 0;
}