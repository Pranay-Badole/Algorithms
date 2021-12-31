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




int check_tabulation(int coin[], int n, int sum, std::vector<std::vector<int>> &dp){
	rep(i,0,n+1){
		rep(j,0,sum+1){
			if(i==0){dp[i][j] = 0;}
			if(j==0){dp[i][j] = 1;}
		}
	}

	rep(i,1,n+1){
		rep(j,1,sum+1){
			if(coin[i-1]<=j){
				dp[i][j] = dp[i][j-coin[i-1]] + dp[i-1][j];
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][sum];
}


void solve(){	 

	int n, sum;
	cin>>n>>sum;

	int coin[n];

	rep(i,0,n){
		cin >> coin[i];
	}
	vector<vector<int>> dp(n+1,vector<int>(sum+1));

	int ans = check_tabulation(coin,n,sum, dp);
	
	cout << ans << endl;
	
	rep(i,0,n+1){
		rep(j,0,sum+1){
			cout<<dp[i][j]<<' ';
		}
		cout<<endl;
	}
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