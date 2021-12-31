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

// Same code as peak element

int max_element(std::vector<int> v, int n){
	int l,r,mid;
	l=0;
	r=n-1;
	if(n==1)return 0;

	while(l<=r){
		mid = l + (r-l)/2;
		if( mid>0 && mid<n-1) {
			 if(v[mid-1]<v[mid] && v[mid+1]<v[mid] ){
					return mid;
			}
			else if(v[mid]>v[mid-1]){
					l = mid + 1; 
			}
			else{
				r = mid-1;
			}
		}	
		else if(mid==0){
			if(v[0]>v[1]){return 0;}
			else{return 1;}

		}
		else{
			if(v[n-1]>v[n-2]){return n-1;}
			else{return n-2;}
		}
	}
	return -1;
}

void solve(){
	// BITONIC ARRAY
std::vector<int> v={4};
int n=sz(v);
cout<<max_element(v,n);

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