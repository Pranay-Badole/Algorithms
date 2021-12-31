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

int how_much_rotated(std::vector<int> v,int n){
	int start=0;
	int end=n-1;

	int mid,prev,next;
	int i=1;
	while(start<=end){
		cout<<i++<<' ';
		if(v[start]<=v[end]){

			return start;
		}

		mid = start + (end-start)/2;
		prev=(n+mid-1)%n;
		next=(mid+1)%n;

		if( v[mid]<=v[prev] && v[mid]<=v[next] ){
			return mid;
		}
		if(v[start]<=v[mid]){
			start=mid+1;
		}
		else if(v[mid]<=v[end]){
			end=mid-1;
		}
	}
	return -1;
}

void solve(){
	// Right Rotated or Clockwise roatation
	// std::vector<int> v = {11,12,15,18,2,5,6,8};
	std::vector<int> v = {2,5,6,8,11,12,15,18};

	cout<<how_much_rotated(v,sz(v))<<endl; 		   // for clockwise or right rotated
	cout<<(sz(v)-how_much_rotated(v,sz(v)))%sz(v); // for anticlockwise or left rotated
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