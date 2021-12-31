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

pii floor_and_ceil(std::vector<int> v, int k, int n){
	int start=0;
	int end=n-1;
	int mid;

	while(start<=end){

		mid = start + (end-start)/2;

		if(v[mid]==k) {return {k,k};}

		else{
			if(k > v[mid])start=mid+1;
			else{
				end=mid-1;
			}	
		}
	}
	// cout<<start<<' '<<end<<' ';
	pii ans={-1,-1};

	if(start<=n-1)	ans.sc=v[start];
	if(end>=0) 	ans.fr=v[end];

	return ans;
}

void solve(){
	int w=25;
	// std::vector<int> v = {11,12,15,18,2,5,6,8};
	std::vector<int> v = {3,4,8,10,10,12,19};
	int k;
	int q; cin>>q;
	while(q--){
	cin>>k;
	pii ans = floor_and_ceil(v,k,sz(v));
	cout<<"floor: "<<ans.fr<<' '<<"ceil: "<<ans.sc<<' '<<k<<endl;
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