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
	
void insert(stack<int>&st, int temp){
	if(sz(st)==0){
		st.push(temp);
		return;
	}

	int val = st.top();
	st.pop(); 

	insert(st,temp);
	st.push(val);
}

void reverse(stack<int> &st){
if(sz(st)==1){
	return;
}
int val = st.top();
st.pop();
reverse(st);

insert(st,val);

}

void solve(){
	int n;
	cin>>n;
	stack<int> v;
	int a;
	rep(i,0,n){
		cin>>a;
		v.push(a);
	}
	
	auto z=v;
	while(sz(z)>0){
		cout<<z.top()<<' ';
		z.pop();
	}
	cout<<endl;

	if(sz(v)>0){
	reverse(v);
	}
		
	while(sz(v)>0){
		cout<<v.top()<<' ';
		v.pop();
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