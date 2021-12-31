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
	#define auv(v)		      for(auto x:v) cout<<x<<' '; 
	#define aump(mp)	      for(auto x:mp) cout<<x.fr<<' '<<x.sc<<endl; 
	
 
const int N=1e5+5;
const int M=100000000;


void Print_Subsets(vector<int>ip,vector<int>op,set<vector<int>>&st){
    
    if(ip.size()==0){
    	// if array not sorted initially
    	// sort(all(op));
        st.insert(op);
        return;
    }

	// if sorted in descending order    
    // int val = ip.back();
    // ip.ppb();

    // if sorted in ascending order
    int val = ip.front(); 
    ip.erase(ip.begin());
    
    Print_Subsets(ip,op,st);
    op.push_back(val);
    Print_Subsets(ip,op,st);
    
}

void solve(){
	std::vector<int> arr= {2,3,1,3};
	set<vector<int>>st;

		// sort(all(arr),greater<int>());
		sort(all(arr));

        vector<int>q;
        Print_Subsets(arr,q,st);
         vector<vector<int>>ans;

        for(auto &x:st){
            ans.pb(x);
      }
      for(auto x: ans){
      	for(auto y:x){
      		cout<<y<<' ';
      	}
      	cout<<endl;
      }
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