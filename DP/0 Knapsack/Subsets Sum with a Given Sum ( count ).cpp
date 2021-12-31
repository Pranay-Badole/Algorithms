#include "bits/stdc++.h"
	using namespace std;	
	#define int              long long 
 
	#define pb                push_back
	#define ppb               pop_back
	#define pf                push_front
	#define ppf               pop_front
	#define all(x)            (x).begin(),(x).end()
	#define uniq(v)           (v).erase(unique(all(v)),(v).end())
	#define sz(x)             (int)((x).size())
	#define fr                first
	#define sc                second
	#define pii               pair<int,int>
	#define mkp 				  make_pair
	#define rep(i,a,b)        for(int i=a;i<b;i++)
	#define rrep(i,a,b)        for(int i=a;i>=b;i--)
	#define REP(i,a,b)        for(int i=a;i<=b;i++)
	#define mem1(a)           memset(a,-1,sizeof(a))
	#define mem0(a)           memset(a,0,sizeof(a))
	#define ppc               __builtin_popcount
	#define ppcll             __builtin_popcountll
	#define acc				  accumulate
	#define endl			  '\n'
	#define length(a)		  sizeof(a)/sizeof(a[0])
	#define auv(v)		      for(auto x:v) cout<<x<<' '; 
	#define aump(mp)	      for(auto x:mp) cout<<x.fr<<' '<<x.sc<<endl; 
	
 
const int N=1e5+5;
const int M=100000000;


int check(int a[], int n, int sum){
	if(sum == 0){return 1;}
	if(n == 0){ return 0;}

	if(a[n-1]<=sum){
		return (check(a,n-1,sum-a[n-1])+check(a,n-1,sum));
	}
	else{
		return check(a,n-1,sum);
	}

}


int check_tabulation(int a[], int n, int sum, vector<vector<int>> &dp){
	// cout<<sz(dp)<<' '<<sz(dp[0])<<endl;
	rep(i,0,n+1){
		rep(j,0,sum+1){
			if(i==0){dp[i][j]=0;}
			if(j==0){dp[i][j]=1;}
		}
	}

	rep(i,1,n+1){
		rep(j,1,sum+1){
			if(a[i-1]<=j){
				dp[i][j] = dp[i-1][j-a[i-1]] + dp[i-1][j];
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][sum];
}
void solve(){	 

	int n,sum;
	cin>>n>>sum;

	int a[n];
	rep(i,0,n){cin>>a[i];}

	vector<vector<int>> dp (n+1,vector<int> (sum+1));
	
	int ans = check_tabulation(a,n,sum,dp);
	cout<<ans;
}	

	signed main(){
		ios_base::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		#ifndef ONLINE_JUDGE
			freopen("input.txt","r",stdin);
			freopen("output.txt","w",stdout);
		#endif
		#ifdef SIEVE
			sieve();
		#endif
		#ifdef NCR
			init();
		#endif
 
		int t=1;
		// cin>>t;
		while(t--) solve(),cout<<endl;
		return 0;
	}