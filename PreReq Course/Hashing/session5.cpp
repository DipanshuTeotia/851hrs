/*
    Q.Given an array “nums” of size “N” - find the total number of pairs(i,j) [i<j] such that abs(nums[i] + nums[j]) = target,target>=0
    Logic:
        1.traverse on nums and reach a certain index j
        2.then look at the left side of j and find any nums[i] that can full fill the above requirements
        3.abs(nums[i]+nums[j])=target
        then nums[i]+nums[j]=target and -nums[i]-nums[j]=target
        then val1=-nums[j]+target and val2=-nums[j]-target
        4.now if the above condition hits anytime increase the counter
        5.then make the entry in hashmap

    Example:
        10 5 1 3 1
        target:2
        output:1
*/

#include<bits/stdc++.h>
using namespace std;

void slv(){
    int n,target;
    cin>>n>>target;

    vector<int>nums(n);
    for(auto &it:nums){
        cin>>it;
    }

    unordered_map<int,int>mp;
    int cnt=0;
    for(int j=0;j<n;j++){
        int val1 = -nums[j] + target;
        int val2 = -nums[j] - target;
        if(mp.count(val1)){
            cnt+=mp[val1];
        }
        if(mp.count(val2)){
            cnt+=mp[val2];
        }
        mp[nums[j]]++;
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