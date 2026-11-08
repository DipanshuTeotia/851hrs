#include<bits/stdc++.h>
using namespace std;

// 1.time is n*q for each query
void slvByNormalWay(int n , int query , vector<int>&arr){
    int count=0;
    for(auto it : arr){
        if(it==query){
            count++;
        }
    }
    cout<<count<<endl;
}

// 2.time reduce hua n+q mai but sapce increse ho gyi
void slvByFreqArray(int n,int query,vector<int>&arr){
    sort(arr.begin(),arr.end());
    int maxi=arr[n-1];
    vector<int>freq(maxi+1);
    for(auto it:arr){
        freq[it]++;
    }
    cout<<freq[query]<<endl;
}

// 3.yaha pe space bhi reduce ho gyi
void slvByHashMap(int n,int query,vector<int>&arr){
    unordered_map<int,int>mp;
    for(auto it : arr){
        mp[it]++;
    }
    cout<<mp[query]<<endl;
}

int main(){
    /*
        why hashing : i have to find how many time a query(specific number) is comming in the array
        1.normal way : 1 loops and maintain count : tc(O(n*q)) sc(O(1))
        2.frequency array or hashing array : tc(O(n+q)) sc(O(largest number in the array + 1))
        3.hashmap => unordered map : tc(O(1)) sc(O(unique numbers in array))
    */

    int t;
    cin>>t;
    while(t-->0){
        int n,query;
        cin>>n>>query;
        vector<int>arr(n);
        for(auto &it:arr){
            cin>>it;
        }
    
        slvByNormalWay(n, query, arr);
        slvByFreqArray(n,query,arr);
        slvByHashMap(n,query,arr);
    }
    return 0;
}