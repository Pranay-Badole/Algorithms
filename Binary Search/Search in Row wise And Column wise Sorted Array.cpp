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
	#define pii              pair<int,int>
	#define mkp 				  make_pair
	#define rep(i,a,b)        for(int i=a;i<b;i++)
	#define rrep(i,a,b)       for(int i=a;i>=b;i--)
	#define REP(i,a,b)        for(int i=a;i<=b;i++)
	#define mem1(a)   
	#define mem0(a)           memset(a,0,sizeof(a))
	#define ppc               __builtin_popcount
	#define ppcll             __builtin_popcountll
	#define acc				  accumulate
	#define endl			  '\n'
	#define length(a)		  sizeof(a)/sizeof(a[0])
	#define auv(v)		      for(auto x:v) cout<<x<<' '; 
	#define aump(mp)	      for(auto x:mp) cout<<x.fr<<' '<<x.sc<<endl; 
 

	typedef pair<int,pair<int,int>> ppi;
	
const int N=200005;
const int M=998244353;

pii find(vector<vector<int>> v, int key){
	int n=sz(v);
	int m=sz(v[0]);

	int i=0, j=m-1;
	int cnt=0;
		while(i>=0 && j>=0 && i<n && j<m){
			// cout<<cnt++<<' ';
			// cout<<v[i][j]<<' '<<endl;
			if(v[i][j]==key){
				return{i,j};
			}
			if(key > v[i][j]){i++;}
			else if(key < v[i][j]){j--;}
		}
	return {-1,-1};
}

void solve(){
	int n=4, m=4;
	vector<vector<int>> v(n,vector<int>(m,0));
	rep(i,0,n){
		rep(j,0,m){
			cin>>v[i][j];
		}
	}
	int q;cin>>q;
	while(q--){
	int key;cin>>key;
	pii a = find(v,key);
	cout<<endl;
	cout<< a.fr << ' ' << a.sc;
	}
}
	signed main(){
		ios_base::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		#ifndef ONLINE_JUDGE
			freopen("input.txt","r",stdin);
			freopen("output.txt","w",stdout);
		#endif
		// #ifdef SIEVE
		// 	sieve();
		// #endif
		// #ifdef NCR
		// 	init();
		// #endif

		int t=1;
		// cin>>t;
		while(t--) solve();
		return 0;
	}