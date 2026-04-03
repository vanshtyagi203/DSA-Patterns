#include<bits/stdc++.h>
using namespace std;

vector<int> mergeSortArr(int n,int m,vector<int> &even, vector<int> &odd){
    
    vector<int> res;
    int i=0;
    int j=0;

    while(i<n && j<m){
        if(even[i]<odd[j]){
            res.push_back(even[i]);
            i++;
        }
        else{
            res.push_back(odd[j]);
            j++;
        }
    }
    while(j<m){
        res.push_back(odd[j]);
        j++;
    }
    while(i<n){
        res.push_back(even[i]);
        i++;
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int>even(n);
    for(int i=0;i<n;i++){
        cin>>even[i];
    }
    int m;
    cin>>m;
    vector<int>odd(m);

    for(int i=0;i<m;i++){
        cin>>odd[i];
    }

    vector<int> res=mergeSortArr(n,m,even,odd);
    for(int i=0;i<res.size();i++){
        cout<<res[i];
    }
    return 0;
}