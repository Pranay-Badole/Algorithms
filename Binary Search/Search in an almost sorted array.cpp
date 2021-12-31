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

***IMP
 // diff approach

// int find(std::vector<int> v, int k, int n){
// 	int start=0;
// 	int end=n-1;
// 	int mid;

// 	while(start<end-1){

// 		mid = start+ (end-start)/2;

// 		if(v[mid]==k) {return mid;}
// 		else if(v[mid-1]==k){return mid-1;}
// 		else if(v[mid+1]==k){return mid+1;}
// 		else{
// 			if(k > v[mid])start=mid+2;
// 			else{
// 				end=mid-2;
// 			}	
// 		}
// 	}
// 	cout<<start<<' '<<end<<' ';
// 	if(v[start]==k) return start;
// 	else if (v[end]==k) return end;
// 	return -1;
// }

int find(std::vector<int> v, int k, int n){
	int start=0;
	int end=n-1;
	int mid;

	while(start<=end){

		mid = start+ (end-start)/2;

		if(v[mid]==k) {return mid;}
		else if(mid>start && v[mid-1]==k){return mid-1;}
		else if(mid<end && v[mid+1]==k){return mid+1;}
		else{
			if(k > v[mid])start=mid+2;
		else{
			end=mid-2;
		}	
		}
	}
	return -1;
}

void solve(){

	// std::vector<int> v = {11,12,15,18,2,5,6,8};
	std::vector<int> v = {10, 3, 40, 20, 50, 80, 70};
	int k;
	int q; cin>>q;
	while(q--){
	cin>>k;
	cout<<find(v,k,sz(v))<<' ';
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