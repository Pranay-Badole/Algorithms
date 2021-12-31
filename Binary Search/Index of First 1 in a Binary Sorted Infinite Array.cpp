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

int find(std::vector<int> v, int n){
	int start = 0;
	int end = 1;

	while(v[end]!=1 ){
		start=end;
		end*=2;
		// if(end>=n){   // uncomment to have ans for
		// 	end=n-1;  	 // finite binary array
		// 	break;
		// }
	}
	// cout<<start<<' '<<end<<' ';
	int mid, pivot=-1;

	while(start<=end){
		mid = start + (end - start)/2;
		if(v[mid]==0){
			start=mid+1;
		}
		else{
			pivot=mid;
			end=mid-1;
		}
	}
	return pivot;
}

void solve(){

	// std::vector<int> v = {11,12,15,18,2,5,6,8};
	std::vector<int> v = {0,0,0,0,0,0,0,0,0,1,1,1,1,1,1, , , , ,};
	int n=sz(v);
	cout<<find(v,n)<<' ';
	
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