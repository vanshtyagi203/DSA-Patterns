#include<bits/stdc++.h>
using namespace std;
vector<int> squareSortArr(vector<int> &arr,int n){
       vector<int> pos;
       vector<int>neg;

       for(int i=0;i<n;i++){
         if(arr[i]<0){
            neg.push_back(arr[i]);
         }
         else{
            pos.push_back(arr[i]);
         }
       }

       if(pos.size()==0){
        for(int i=0;i<neg.size();i++){
            neg[i]=neg[i]*neg[i];
        }
        reverse(neg.begin(),neg.end());
        return neg;
       }

       if(neg.size()==0){
        for(int i=0;i<pos.size();i++){
            pos[i]=pos[i]*pos[i];
        }
        return pos;
       }


       vector<int> res;
       
       
       for(int i=0;i<pos.size();i++){
        pos[i]=pos[i]*pos[i];
       }

       for(int i=0;i<neg.size();i++){
        neg[i]=neg[i]*neg[i];
       }
       reverse(neg.begin(),neg.end());

       int i=0;
       int j=0;
       while(i<pos.size()&&j<neg.size()){
           if(pos[i]<neg[j]){
             res.push_back(pos[i]);
             i++;
           }
           else{
            res.push_back(neg[j]);
            j++;
           }
       }

       while(i<pos.size()){
        res.push_back(pos[i]);
        i++;
       }
       while(j<neg.size()){
        res.push_back(neg[j]);
        j++;
       }
        
       return res;

       }

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> res=squareSortArr(arr,n);
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    return 0;
}