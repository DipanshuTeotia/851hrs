/*
    Q.Given an array “nums” of size “N” - find the total number of pairs(i,j) [i<j] such that nums[i] - nums[j] = target
    Logic: 
        use the j trick 
        1.traverse the vector and reach till j index 
        2.now look at the left of the j index and try to find nums[i] i.e target+nums[j]
        3.if it exists in the hashmap : then add the frequency of this in cnt 
        4.else just make the entry in the hash map
    Logical Question:
        why we use mp.exists(val) ?
        so that no extra entry is created in the hashmap
    Example vector
    5 5 3 3 2 2 
    target:2
    output:2 
*/

#include<bits/stdc++.h>
using namespace std;

void slv(){
    int n,target;
    cin>>n>>target;
    vector<int>arr(n);
    for(auto &it:arr){
        cin>>it;
    }

    int cnt=0;
    unordered_map<int,int>mp;
    for(int j=0;j<n;j++){
        int val=target+arr[j];
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