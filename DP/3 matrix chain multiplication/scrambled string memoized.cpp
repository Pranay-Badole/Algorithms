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
	#define rrep(i,a,b)        for(int i=a;i>=b;i--)
	#define REP(i,a,b)        for(int i=a;i<=b;i++)
	#define mem1(a)           memset(a,-1,sizeof(a))
	#define mem0(a)           memset(a,0,sizeof(a))
	#define ppc               __builtin_popcount
	#define ppcll             __builtin_popcountll
	#define acc				  accumulate
	#define endl			  '\n'
	#define length(a)		  sizeof(a)/sizeof(a[0])
	#define auv(v)		      for(auto &x:v) cout<<x<<' '; cout<<endl;
	#define auvv(v)			  for(auto &x:v){for(auto &y:x)cout<<y<<' ';cout<<endl;}
	#define aump(mp)	      for(auto x:mp) cout<<x.fr<<' '<<x.sc<<endl; 
	
 
const int N=1e5+5;
const int M=100000000;


unordered_map<string,int>mp;


int is_scrambled(string a, string b){
	string s = a;
	s.pb('_');
	s+=b;

	if(mp.count(s)){return mp[s];}

	cout<< a <<' '<<b<<endl;
	if(sz(a)!=sz(b)){
		return mp[s]=0;
	}
	int n = sz(a);
	
	if(n==0){return mp[s]=1;}
	if(n==1){
		if(a==b){return mp[s]=1;}
		return 0;
	}
	if(a==b){return mp[s]=1;}

	int flag = 0;

	rep(k,1,n){

	int q = n-k;
	if( is_scrambled(a.substr(0,k), b.substr(0,k)) && is_scrambled(a.substr(k),b.substr(k))) {
		flag = 1;
		return mp[s]=flag;
	}

	if( is_scrambled(a.substr(0,k), b.substr(q)) && is_scrambled(a.substr(k),b.substr(0,q)) ){
		flag = 1;
		return mp[s]=flag;
	}

	}
	
		return mp[s]=flag;
}
void solve(){	 

		string a, b;
		cin >> a >> b;

		int n = sz(a);
		
		int ans = is_scrambled(a, b);		

		cout << ans ;

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
		while(t--) solve(),cout<<endl;
		return 0;
	}