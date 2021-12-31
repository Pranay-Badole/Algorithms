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
 
bool is_possible(vector<int> v, int mid, int k){
	int sum=0,cnt=1;
	
	rep(i,0,sz(v)){
			sum+=v[i];
			if(sum>mid){
				cnt++;
				sum=v[i];
			}
		}
		// cout<<cnt<<' ';
		if(cnt > k){
			return false;
		}
		else{
			return true;
		}
}

void solve(){
	std::vector<int> v={10, 20, 30, 40};

	int l = *max_element(all(v));
	int r = acc(all(v),0);
	int mid;
	int ans = -1;
	int k = 2;
	// cout<<l<<' '<<r<<endl;  

	while(l<=r){
		mid = l + (r-l)/2;
		// cout<<l<<' '<<r<<' '<<mid<<endl;
		bool flag = is_possible(v,mid,k);
		
		if(flag){
			r = mid-1;
			ans = mid; 
		}
		else{
			l = mid + 1;  
		}
	}
	cout<<ans;
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