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



int knapsack_recursive(std::vector<int>wt, std::vector<int> val, int w, int n){
	if(w==0 || n==0){
		return 0;
	}
	if(wt[n-1]<=w){
		return max(val[n-1]+knapsack_recursive(wt,val,w-wt[n-1],n-1),knapsack_recursive(wt,val,w,n-1));
	}
	else{
		return knapsack_recursive(wt,val,w,n-1);
	}
}	

int dp[102][102];
// mem0(dp);

int knapsack_memoized(std::vector<int>wt, std::vector<int> val, int w, int n){
	if(w==0 || n==0){
		return 0;
	}
	if(dp[w][n]!=-1){
		return dp[w][n];
	}
	if(wt[n-1]<=w){
		return dp[w][n] = max(val[n-1] + knapsack_memoized(wt,val,w-wt[n-1],n-1),knapsack_memoized(wt,val,w,n-1));
	}
	else{
		return dp[w][n] = knapsack_memoized(wt,val,w,n-1);
	}
}

int t[102][102];
int knapsack_tabulation(std::vector<int>wt, std::vector<int> val, int w, int n){
	rep(i,0,w+1){
		rep(j,0,n+1){
			if(i==0 || j==0){
				t[i][j] = 0;
			}
		}
	}
	rep(i,1,w+1){
		rep(j,1,n+1){
	if(wt[j-1]<=i){
		t[i][j] = max(val[j-1]+t[i-wt[j-1]][j-1],t[i][j-1]);
	}
	else{
		t[i][j] = t[i][j-1];
	}
}
}
	return t[w][n];
}


void solve(){	 
	for(auto &x : dp){
		for(auto &y : x){
			y=-1;
		}
	}
	int n,w;
	cin>>n>>w;
	vector<int> wt(n);
	vector<int> val(n);
	rep(i,0,n)cin>>wt[i];
	rep(i,0,n)cin>>val[i];

	// int ans = knapsack_recursive(wt, val, w, n);
	int ans = knapsack_memoized(wt, val, w, n);
	// int ans = knapsack_tabulation(wt, val, w, n);
	cout<<ans<<' '<<dp[w][n]<<endl;

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