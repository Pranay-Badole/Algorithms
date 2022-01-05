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

const int N=200005;
const int M=998244353;

int power(int x,int y,int m){
	if(y==0)return 1;
	int temp=power(x,y/2,m)%m;
		temp= (temp*temp)%m;
	if(y%2){
		temp=x*temp%m;
	}
	return temp;
}	

map<int,int>mp;

void solve(){	
	int n;cin>>n;	
	int a[n+1];

	rep(i,1,n+1){
		cin>>a[i];
		mp[a[i]]=i;
	}

	int i=1;
	int cnt=0;

	while(i<=n){

		int d=mp[a[i]];
		for(i;i<=d;i++){
			if(mp[a[i]]>d){	
				d=mp[a[i]];
			}
		}
		cnt++;
	}

	int ans=power(2,cnt-1,M);
	cout<<ans;
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
		while(t--) solve();
		return 0;
	}