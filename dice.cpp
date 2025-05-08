#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9+7;
long long solve(int sum,vector<long long> &dp){
    if(sum==0) return 1;
    if(dp[sum]!=-1) return dp[sum]%MOD;
    long long take = 0;
    for(int i=1;i<=6;i++){
        if(i<=sum) take+=solve(sum-i,dp)%MOD;
    }
    return dp[sum]=take%MOD;
}
int main() {
	int n;
	
	cin>>n;
	vector<long long> dp(n+1,-1);
	cout<<solve(n,dp)<<endl;

}
