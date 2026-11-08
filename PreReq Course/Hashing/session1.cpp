/*
    Q.Check if there are any two Equal numbers in an array at a distance less than or equal to k
*/

#include<bits/stdc++.h>
using namespace std;

void slv(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(auto &it:arr){
        cin>>it;
    }

    // map bna lo to store last occurance 
    // 1 2 1 2 1 3 4 5 6 3 2
    // k:2
    unordered_map<int,int>mp;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(mp.find(mp[arr[i]])!=mp.end()){
            mp[arr[i]]=i;
        }
        else{
            // now find the diff 
            int prevOccIndex=mp[arr[i]];
            int currOccIndex=i;
            int diff=currOccIndex-prevOccIndex;
            if(diff<=k){
                cnt++;
                cout<<"pair1:("<<arr[i]<<","<<prevOccIndex<<")"<<endl;
                cout<<"pair2:("<<arr[i]<<","<<currOccIndex<<")"<<endl;
            }
            // update to check for the next one 
            mp[arr[i]]=currOccIndex;
        }
    }
    cout<<"yes there are pairs for this :"<<cnt<<endl;
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