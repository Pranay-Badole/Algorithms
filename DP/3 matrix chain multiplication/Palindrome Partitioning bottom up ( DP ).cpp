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
	#define auv(v)		      for(auto &x:v) cout<<x<<' '; cout<<endl;
	#define auvv(v)			  for(auto &x:v){for(auto &y:x)cout<<y<<' ';cout<<endl;}
	#define aump(mp)	      for(auto x:mp) cout<<x.fr<<' '<<x.sc<<endl; 
	
 
const int N=1e5+5;
const int M=100000000;

bool is_palindrome(int i, int j, string &a){
	while(i<=j){
		if(a[i]!=a[j]){
			return false;
		}
		else{
			i++; j--;
		}
	}
	return true;
}

//  RECURSIVE

int fun(int i, int j, string &a){
	if(i >= j || is_palindrome(i, j, a)){
		return 0;
	}
	int ans = INT_MAX;

	for(int k = i; k < j; k++){
		int temp = fun(i, k, a) + fun(k+1, j, a) + 1;
		ans = min(ans, temp);
	}
	return ans;
}

void solve(){	 
	string a;
	cin >> a;
	int n = sz(a);

	vector<vector<int>>dp(n, vector<int>(n,-1));

	for(int i = 0; i < n; i++) dp[i][i] = 0;

	for(int l = 1; l < n; l++){
		for(int i = 0; i < n-l; i++){
			int j = i + l;
			// cout << i << ' ' << j << endl;   

			if(is_palindrome(i, j, a)){
			 	dp[i][j] = 0; 
			}
			else{
			int ans = INT_MAX;
			
			for(int k = i; k < j; k++){
				int temp = dp[i][k] + dp[k+1][j] + 1;
				ans = min(ans, temp);
			}
			dp[i][j] = ans;
			}
		}
	}
	auvv(dp);
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