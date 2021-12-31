#include "bits/stdc++.h"
	using namespace std;



	#define int               long long 
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
	#define mkp 			  make_pair
	#define rep(i,a,b)        for(int i=a;i<b;i++)
	#define rrep(i,a,b)       for(int i=a;i>=b;i--)
	#define REP(i,a,b)        for(int i=a;i<=b;i++)
	#define mem1(a)           memset(a,-1,sizeof(a))
	#define mem0(a)           memset(a,0,sizeof(a))
	#define ppc               __builtin_popcount
	#define ppcll             __builtin_popcountll
	#define acc				  accumulate
	#define endl			  '\n'
	#define length(a)		  sizeof(a)/sizeof(a[0])
	#define auv(v)		      for(auto x:v) cout<<x<<' '; cout<<endl;
	#define auvv(v)			  for(auto x:v){for(auto y:x)cout<<y<<' ';cout<<endl;}
	#define aump(mp)	      for(auto x:mp) cout<<x.fr<<' '<<x.sc<<endl; 
	
 
const int N=1e5+5;
const int M=100000000;


// different approach in DP playlist video
// i approached defferently

int  lcs_tabulation(string x, string y, int n, int m, std::vector<std::vector<int>> &dp){

rep(i,0,n+1){
	rep(j,0,m+1){
		if(i==0 || j==0){
			dp[i][j] = 0;
		}
	}
}

	rep(i,1,n+1){
		rep(j,1,m+1){
			if(x[i-1] == y[j-1]){
				dp[i][j] = (dp[i-1][j-1] + 1);
			}
			else{
				dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
			}
		}
	}
	return dp[n][m];
}

void solve(){	 

	string x, y;
	cin >> x;
	y = x;
	reverse(all(y));

	int n,m;
	
	n = sz(x);
	m = sz(y);

	std::vector<std::vector<int>> dp(n+1,vector<int> (m+1));	

	int ans = lcs_tabulation(x,y,n,m,dp);
	cout << n-ans << endl ;

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