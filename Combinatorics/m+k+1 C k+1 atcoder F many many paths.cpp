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
	#define mem1(a)           memset(a,-1,sizeof(a))
	#define mem0(a)           memset(a,0,sizeof(a))
	#define ppc               __builtin_popcount
	#define ppcll             __builtin_popcountll
	#define acc				  accumulate
	#define endl			  '\n'
	#define length(a)		  sizeof(a)/sizeof(a[0])
	#define auv(v)		      for(auto x:v) cout<<x<<' '; 
	#define aump(mp)	      for(auto x:mp) cout<<x.fr<<' '<<x.sc<<endl; 

const int N=300005;
const int M=1e9+7;

int power(int x,int y,int m){
	if(y==0)return 1;
	int temp=power(x,y/2,m)%m;
		temp= (temp*temp)%m;
	if(y%2){
		temp=x*temp%m;
	}
	return temp;
}	


int fact[N];
int invfact[N];

void factorial(){
	fact[0]=1;
	rep(i,1,N){
		fact[i]=i*fact[i-1]%M;
	}
	invfact[N-1]=power(fact[N-1],M-2,M);
 rrep(i,N-2,0){
 	invfact[i]=(i+1)*invfact[i+1]%M;
 }
}

int ncr(int n,int r){
	if(r > n || n < 0 || r < 0)return 0;
	return fact[n]*invfact[r]%M*invfact[n-r]%M;
}


void solve(){
	factorial();
	int r1,r2,c1,c2;
	cin>>r1>>c1>>r2>>c2;
	int ans=0;
	REP(m,r1,r2){
		ans+=(ncr(m+c2+1,c2)-ncr(m+c1,c1-1)+M)%M;
	}
	cout<<ans%M;
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