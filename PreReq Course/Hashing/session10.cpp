/*
    Q.Given an array of size “N” -> count the number of subarrays[i…j] whose sum is “K” (Array is not sorted) -> [If array was sorted we could have used the “Two Pointer” algorithm which we will learn about in the brilliant “Two Pointer” course]

    Logic :
        1.find the prefix sum first to identify the sum of various subarrays
        2.now apply the j trick
        3.traverse on the prefix sum arrary and reach to a certain index j
          then look at the left side of the array
          core requirement : find the subarray whose sum is K
                             subarray : p[j]-p[i]=k
          hence p[i]=p[j]-k
        4.now on the go keep updating the hashmap

    Example :
    input:2 2 3 5 2 2 3 2 2 1
    k:8
    output:2
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
        p[i]=p[i-1]+a[i];
    }

    //now apply j trick with hashmap to find the subarray range whose sum can be equal to k
    int cnt=0;
    unordered_map<int,int>mp;
    // edge case here mp[0]=1 accounts for if p[j]==k then the val(p[i]) will be 0
    // but it is not in hashmap so add this 
    // as the range 0 to j count as 1 if sum is equal to k
    mp[0]=1;
    for(int j=0;j<n;j++){
        int val=p[j]-k;
        if(mp.count(val)){
            cnt+=mp[val];
        }
        mp[p[j]]++;
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