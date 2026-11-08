#include<bits/stdc++.h>
using namespace std;

/*
    Q. We are given an Array of Numbers. We have to find and print any Number with Maximum Frequency and Minimum Frequency
    sol:
        1.use unorderedmap : best but the worst tc(O(n))
        2.use map : due to the limitation of unorderedmap we can use map
        3.use frequency array : if the numbers have smaller max number use this 
        best and easy : unordered_map
*/

void slv(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &it:arr){
        cin>>it;
    }
    // hashmap is ready for all the input of the vector
    unordered_map<int,int>mp;
    for(auto it : arr){
        mp[it]++;
    }
    // now find the key which have max and min frequency
    int maxi=INT_MIN;
    int mini=INT_MAX;
    int maxVal,minVal;
    maxVal=minVal=0;
    for(auto it:mp){
        if(maxi<it.second){
            maxi=it.second;
            maxVal=it.first;
        }
        if(mini>it.second){
            mini=it.second;
            minVal=it.first;
        }
    }
    cout<<maxVal<<"->"<<maxi<<endl;
    cout<<minVal<<"->"<<mini<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        slv();
    }
    return 0;
}