/*
    Q.Given an array “nums” of size “N” - find the total number of pairs(i,j) [i<j]
    such that (nums[i] + nums[j])%k = 0 (nums[i]>=0,K>=2)

    Logic :
        use j trick
        1.traverse the vector nums then reach at a certain index j
        2.after that check for the core requirement statisfaction in the left of the j index
        3.core requirement is :
            (nums[i] + nums[j])%k = 0
            that is 
            rem=nums[j]%k
            val=k-rem
            now if val exists in the hashmap then all done increae the counter 
        4.insert the nums[j]%k in hashmap 

    Example:
        I/P:2 2 5 5 3 3 
        k:5
        o/p:5

    TC:O(n)
    SC:O(k)

*/

#include<bits/stdc++.h>
using namespace std;

void slv(){
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    for(auto &it:nums){
        cin>>it;
    }

    int cnt=0;
    unordered_map<int,int>mp;
    for(int j=0;j<n;j++){
        int rem=nums[j]%k;
        int val=k-rem;

        // edge case 
        if(rem==0){
            val=0;
        }

        if(mp.count(val)){
            cnt+=mp[val];
        }
        mp[nums[j]%k]++;
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