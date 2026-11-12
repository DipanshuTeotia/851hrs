/*
    Q.Find count of shortest/largest subarrays with sum k in given array
    Logic :
        use prefixSum + 2 Hashmap(for prefixSum and lengths) + jtrick
*/

#include<bits/stdc++.h>
using namespace std;

void slv(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(auto &it:a){
        cin>>it;
    }

    // 1.prefix Sum
    vector<int>p(n);
    p[0]=a[0];
    for(int i=1;i<n;i++){
        p[i]=p[i-1]+a[i];
    }

    // hashmap for prefixSum and jtrick to calculate lengths 
    unordered_map<int,int>mp1; //<prefixSum,index>
    unordered_map<int,int>mp2;
    mp1[0]=-1;
    for(int j=0;j<n;j++){
        // core requirement : subarray ka sum k ke equal hona chiye 
        /*
            now let p[i+1]+p[j]==k hai 
                then p[i]=p[j]-k se muje p[i+1] se p[j] ke subarray ka sum mill jayega 
        */
        int val=p[j]-k;
        if(mp1.find(val)!=mp1.end()){
            // now calulate the length 
            int s_idx=mp1[val];
            int l_idx=j;
            int length=l_idx-s_idx;
            //now insert this in hashmap2
            mp2[length]++;
        }
        // on the go first hashmap ko update krte rho
        mp1[p[j]]=j;
    }

    // now traverse in the 2nd hashmap and find the longest and shortest subarray whose sum is k
    int maxi=INT_MIN;
    int mini=INT_MAX;
    int longest,shortest;
    for(auto it:mp2){
        if(maxi<it.first){
            maxi=it.first;
        }
        if(mini>it.first){
            mini=it.first;
        }
    }
    longest=mp2[maxi];
    shortest=mp2[mini];
    cout<<longest<<" "<<shortest<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        slv();
    }
}