/*
    Q.Check if there are any two Equal numbers in an array at a distance less than or equal to k
    logic : 
        1.first traverse the hashmap and store the freq of each element of the array
        2.now stand at any particular j index 
        3.then check if the left to that index any element exists that can make arr[j]+element=target 
        4.if yes then store the frequency of it cnt+=mp[val]
        5.now check of every element 
*/

#include<bits/stdc++.h>
using namespace std;

void slv(){
    int n,target;
    cin>>n>>target;
    vector<int>arr(n);
    for(auto &it : arr){
        cin>>it;
    }

    int cnt=0;
    unordered_map<int,int>mp;
    for(int j=0;j<n;j++){
        int val=target-arr[j];
        if(mp.count(val)){
            cnt+=mp[val];
        }
        mp[arr[j]]++;
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
