/*
    Q.Given an array of size “N” -> count the number of subarrays[i…j] whose bit-wise Xor is “K”
    Logic:
        imp: a^b=c this means a=b^c
        use prefix array + jtrick + hashmap
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

    int cnt=0;
    unordered_map<int,int>mp;  //<prefix-xor,frequency>
    // if p[j]=k then p[i]=p[j]^k=0 that means the complete subarray is counted 
    mp[0]=1;
    for(int j=0;j<n;j++){
        int val=p[j]^k;
        if(mp.count(val)){
            cnt+=mp[val];
        }

        // on the go hash map ko update kr do
        mp[p[j]]+=1;
    }
    cout<<cnt<<endl;
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