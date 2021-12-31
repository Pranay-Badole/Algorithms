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

// *IMP*
// imp after binary search completes and we didn't find the element 'k'
// then l points to the ceil of 'k' & 
// r points to the floor of 'k'
// Can be used to find floor and ceil of an element

int find(std::vector<int> v, int k, int n){
	int l=0;
	int r=n-1;
	int mid;	
	int ans;
	while(l<=r){
		mid = l + (r-l)/2;

		if(v[mid]==k){
			return v[mid];
		}
		else if(v[mid]<k){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	if(r < 0)  {return v[l];}
	if(l > n-1){return v[r];}
	(abs(v[l]-k) < abs(k-v[r]))?ans=l:ans=r;

	return v[ans];
}

void solve(){

	// std::vector<int> v = {11,12,15,18,2,5,6,8};
	std::vector<int> v = {1,6,10};
	int n=sz(v);
	int q; cin>>q;
	while(q--){
	int k;cin>>k;
	cout<<find(v,k,n)<<' ';
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