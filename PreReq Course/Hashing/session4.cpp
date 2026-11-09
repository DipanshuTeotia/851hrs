/*
    Q. Given an array “nums” of size “N” - find the total number of pairs(i,j) [i<j] 
    such that 
    abs(nums[i] - nums[j]) = target where target>=0 
    (Note :- target always should be >=0 in this question because abs(something) is always >=0)

    Logic:
        use j trick
        1.first traverse the vector and reach to a certain index j 
        2.then after reachin j now check for the left side of the j for the required output 
        3. abs(nums[i]-nums[j])=target
           remove the abs
           nums[i]-nums[j]=target
           or
           nums[j]-nums[i]=target
           hence,
           nums[i]=nums[j]+target or nums[i]=nums[j]-target
        4.now find these two possiblities in the hashmap 
        5.if exists increase the counter for these 
        6.if not make the entry for nums[j] in the hashmap

    example:
        7,2,2,3,3,5,5
        target:2
        output:6
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
        int val1=nums[j]+target;
        if(mp.count(val1)){
            cnt+=mp[val1];
        }
        int val2=nums[j]-target;
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
