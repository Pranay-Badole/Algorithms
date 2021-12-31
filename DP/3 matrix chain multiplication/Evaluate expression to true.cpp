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



int fun(string s, int i, int j,bool istrue){

	if(i>j) return false;
	if(i==j){
		if(istrue == true) return (s[i]=='T'); 
		else{ return (s[i]=='F');}
	}
	int ans = 0;

	for(int k = i+1; k<j; k+=2){
		int lt = fun(s,i,k-1,true);
		int lf = fun(s,i,k-1,false);
		int rt = fun(s,k+1,j,true);
		int rf = fun(s,k+1,j,false);

		if(s[k]=='|'){
			if(istrue == false){
				ans += lf*rf;
			}
			else{
				ans+= lt*rt + lt*rf + lf*rt; 
			}
		}
		else if(s[k]=='&'){
			if(istrue == true){
				ans += lt*rt;
			}
			else{
				ans+= lt*rf + lf*rt + lf*rf; 
			}
		}
		else{
			if(istrue == true){
				ans += lt*rf + lf*rt;
			}
			else{
				ans+= lt*rt + lf*rf; 
			}
		}
	}
	return ans;
}

int dp[1000][1000][2];

// can also be done using map
// string --> int
// "i_j_istrue"

int memoized_fun(string s, int i, int j,bool istrue){

	if(i>j) return false;
	if(i==j){
		if(istrue == true) return (s[i]=='T'); 
		else{ return (s[i]=='F');}
	}
	int k = (istrue == true);
	if(dp[i][j][k]!=-1){
		return dp[i][j][k];
	}

	int ans = 0;
	for(int k = i+1; k<j; k+=2){
		int lt,rt,lf,rf;
		lt = dp[i][k-1][1];
		lf = dp[i][k-1][0];
		rt = dp[k+1][j][1];
		rf = dp[k+1][j][0];

		 if(lt==-1){lt = fun(s,i,k-1,true);	dp[i][k-1][1]=lt;}
		 if(lf==-1){lf = fun(s,i,k-1,false); dp[i][k-1][0]=lf;}
		 if(rt==-1){rt = fun(s,k+1,j,true);	dp[k+1][j][1]=rt;}
		 if(rf==-1){rf = fun(s,k+1,j,false); dp[k+1][j][0]=rf;} 

		if(s[k]=='|'){
			if(istrue == false){
				ans += lf*rf;
			}
			else{
				ans+= lt*rt + lt*rf + lf*rt; 
			}
		}
		else if(s[k]=='&'){
			if(istrue == true){
				ans += lt*rt;
			}
			else{
				ans+= lt*rf + lf*rt + lf*rf; 
			}
		}
		else{
			if(istrue == true){
				ans += lt*rf + lf*rt;
			}
			else{
				ans+= lt*rt + lf*rf; 
			}
		}
	}
	return dp[i][j][k] = ans;
}


void solve(){	 
	mem1(dp);
	string s;
	cin>>s;
	int n = sz(s);
	// int ans = memoized_fun(s, 0, n-1, true);
	int ans = fun(s, 0, n-1, true);
	cout << ans << endl;

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