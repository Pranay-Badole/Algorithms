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

int is_palindrome(string s, int i, int j){
while(i<=j){
	if(s[i]!=s[j]){
		return 0;
	}
	i++;j--;
}
return 1;
}


int check_recursive(string s, int i, int j){
	if(i>=j){
		return 0;
	}
	if(is_palindrome(s,i,j)){
		return 0;
	}
	int min = INT_MAX;
	rep(k, i, j){
		int temp_ans = check_recursive(s,i,k) + check_recursive(s,k+1,j) + 1;
		if(temp_ans < min){
			min = temp_ans; 
		}
	}
	return min;
}
int dp[1000][1000];

int check_memoized(string s, int i, int j){
	if(i>=j){
		return 0;
	}

	if(is_palindrome(s,i,j)){
		return 0;
	}

	if(dp[i][j]!=-1){
		return dp[i][j];
	}

	int min = INT_MAX;
	rep(k, i, j){
		int temp_ans = check_memoized(s,i,k) + check_memoized(s,k+1,j) + 1;
		if(temp_ans < min){
			min = temp_ans; 
		}
	}
	return dp[i][j] = min;
}


void solve(){	 
	mem1(dp);

	string s;
	cin >> s;

	int n = sz(s);
	// int ans = check_recursive(s, 0, n-1);
	int ans = check_memoized(s, 0, n-1);
	cout << ans << endl;

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