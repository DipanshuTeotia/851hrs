/*
    Subarrays in an array
    use the same j trick
    so j trick is used for finding pair,triplets and subarrays

    Q.Given an array of size “N” and “Q” queries of the form (L,R) - for each query find the sum of elements in the range [L…R] in the array
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

    vector<int>prefixSum(n);
    prefixSum[0]=nums[0];
    for(int i=1;i<n;i++){
        prefixSum[i]=prefixSum[i-1]+nums[i];
    }

    /*
        l:4 r:10 -> 2+3+4+5+6+7+8 = 35
        1 1 1 2 3 4 5 6 7 8 
        1 2 3 5 8 12 17 23 30 38 
        p[r]-p[l-1] = 38-3 = 35
    */

    int Q;
    cin>>Q;
    while(Q--){
        int l,r;
        cin>>l>>r;
        int sum=0;
        if(l==0){
            sum=prefixSum[r];
        }
        else{
            sum=prefixSum[r]-prefixSum[l-1];
        }
        cout<<sum<<endl;
    }
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