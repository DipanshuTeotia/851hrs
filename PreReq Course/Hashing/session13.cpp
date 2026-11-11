/*
    Q.Given an array of size “N” -> find the largest subarray[i…j] whose bit-wise Xor is “K”
*/

#include<bits/stdc++.h>
using namespace std;

void slv(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(auto &it:a){
        cin>>it;
    }

    vector<int>p(n);
    p[0]=a[0];
    for(int i=1;i<n;i++){
        p[i]=p[i-1]^a[i];
    }

    unordered_map<int,int>mp;  //prefix-xor,index 
    mp[0]=-1;
    int length=INT_MIN;
    for(int j=0;j<n;j++){
        int val=p[j]^k;
        if(mp.count(val)){
            length=max(length,j-mp[val]);
        }
        // on the go hashmap keeps getting updated 

        // and for the longest subarray
        if(mp.find(p[j])==mp.end()){
            mp[p[j]]=j;
        }
    }
    cout<<length<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        slv();
    }
    return 0;
}