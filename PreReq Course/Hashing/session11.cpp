/*
    Q.Given an array of size “N” -> find the largest and shortest subarray[i…..j]  with sum equal to “K”-> In case the answer is not possible print (-1 -1)
    (Array is not sorted) -> [If array was sorted we could have used the “Two Pointer” algorithm which we will learn about in the brilliant “Two Pointer” course]
*/

// find the length of the subarray whose sum is K

#include<bits/stdc++.h>
using namespace std;

void slv(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(auto &it:a){
        cin>>it;
    }

    vector<int>p(n);
    p[0]=a[0];
    for(int i=1;i<n;i++){
        p[i]=p[i-1]+a[i];
    }

    // use j trick 

    /*
        0 1 2 3 4  5  6  7  8  9  10 11 (index)
        2 2 2 2 2  3  3  2  5  3  1  1  (elements)
        2 4 6 8 10 13 16 18 23 26 27 28 (prefix)
        1.move to a ceratin index j and then look at the left side of the index for core requirement 
        2.core requirement : shortest and longest length of the subarray whose sum is k
            for first find all the lengths of subarrays whose sum is k
            p[j]-p[i]=k that means from index i+1 to j sum of all the elements will be k,
                                        so the length will be j-i+1
            p[i]=p[j]-k
        3.on the go hash map ko bhi update krte rhna 
        4.then length vale vector se longest and shortest length find kr lena 
    */
   
    unordered_map<int,pair<int,int>>mp;
    mp[0]={-1,-1};
    int longest=INT_MIN;
    int shortest=INT_MAX;
    for(int j=0;j<n;j++){
        int val=p[j]-k;
        if(mp.count(val)){
            int fIndex=mp[val].first;
            int lIndex=mp[val].second;

            longest=max(longest,j-fIndex+1);
            shortest=min(shortest,j-lIndex+1);
        }

        // on the go update the hashmap
        if(mp.count(p[j])){
            mp[p[j]].second=j;
        }
        else{
            mp[p[j]]={j,j};
        }
    }
    if(longest==INT_MIN){
        cout<<"-1 -1"<<endl;
    }
    else{
        cout<<longest<<" "<<shortest<<endl;
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