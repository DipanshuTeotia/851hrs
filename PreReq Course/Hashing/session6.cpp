/*
    Q.Given an array “nums” of size “N” - find the total number of pairs(i,j) [i<j]
    such that
    (nums[i] + nums[j])%5 = 0 (nums[i]>=0 for all i)

    Logic:
        use j trick
        1.traverse the nums vector and move to a certain index j
        2.now check on the left side of j for the core requirement
        3.core requirement => (nums[i]+nums[j])%5=0
        that is nums[j]%5 = rem
                val=5-rem
                now check on the left side of the j index if there exists a element whose mod by 5 is equal to val
                if yes => increase the count
        5.insert in the hashmap nums[j]

    Example:
        I/P:2,2,5,5,3,3
        O/P:5
*/

#include<bits/stdc++.h>
using namespace std;

void slv(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(auto &it:nums){
        cin>>it;
    }

    unordered_map<int,int>mp;
    int cnt=0;
    for(int j=0;j<n;j++){
        int rem=nums[j]%5;
        cout<<"rem:"<<rem<<endl;
        int val=5-rem;
        cout<<"val:"<<val<<endl;
        // edge case for 5 
        if(rem==0){
            val=0;
        }

        if(mp.count(val)){
            cout<<"cnt++"<<endl;
            cnt+=mp[val];
        }
        mp[nums[j]%5]++;
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