/*
    Q.Find the count of triplets (i,j,k) such that (a[i]+a[j]+a[k])%d==0

    Logic :
        use j trick or here k trick
        1.traverse in vector and fix the k index
        2.now look at the left side of the index k and find the pair that satisfy the core requirement
        3.core requirement
            (a[i]+a[j]+a[k])%d==0
            k is fixed i.e i have a[k] so for the remaining portion to be divisible by d
            (a[i]+a[j])%d==0
            for this a[i]+a[j] should be d-a[k]
            if u find such pair on the left side of the k then increase the counter with mp[d-a[k]]
        4.now on the go store all the pairs and update them too

    Example :
        t:1
        n:6
        i/p:2 2 5 5 3 3
        d:5
        o/p:8
*/

#include<bits/stdc++.h>
using namespace std;

void slv(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto &it:a){
        cin>>it;
    }
    int d;
    cin>>d;

    int cnt=0;
    unordered_map<int,int>mp;
    for(int k=0;k<n;k++){
        int rem=a[k]%d;
        int val=d-rem;
        if(rem==0){
            val=0;
        }

        if(mp.count(val)){
            cnt+=mp[val];
        }

        // maintain hashmap on the go
        for(int u=0;u<=k-1;u++){
            int sum=a[u]+a[k];
            mp[sum%d]++;
        }
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