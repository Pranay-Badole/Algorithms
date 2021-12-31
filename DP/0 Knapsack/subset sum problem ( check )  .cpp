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


bool check(std::vector<int> v, int n, int sum){
	if(sum == 0){return true;}
	if(n==0){return false;}

	if(v[n-1]<=sum){
	return ( check(v, n-1, sum-v[n-1]) || check(v, n-1, sum) );
	}
	else{
		return check(v,n-1,sum);
	}
}

int dp[102][102];

bool check_tabulation(std::vector<int> v, int n, int sum){
	rep(i,0,n+1){
		rep(j,0,sum+1){
			if(i==0){dp[i][j]=0;}
			if(j==0){dp[i][j]=1;}
		}
	}
	rep(i,1,n+1){
		rep(j,1,sum+1){
		if(v[i-1]<=j){
			dp[i][j] = dp[i-1][j-v[i-1]] || dp[i-1][j];
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
	vector<int> v(n);
	rep(i,0,n)cin>>v[i];

	// bool ans = check(v, n, sum);
	bool ans = check_tabulation(v, n, sum);
	cout<<ans<<' '<<endl;

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