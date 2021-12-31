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

**IMP
 // efficient code for solution size
int findPeakElement(const vector<int> &num) {
        int low = 0, high = num.size() - 1;
        while (low < high - 1) {
            int mid = (low + high) / 2;
            if (num[mid] > num[mid - 1] && num[mid] > num[mid + 1]) 
                return mid;
            else if (num[mid] > num[mid + 1]) 
                    high = mid - 1;
                 else 
                    low = mid + 1;    
        }
        return num[low] > num[high] ? low : high;
    }

int peak(std::vector<int> v, int n){
	int l=0;
	int r=n-1;
	int mid;
	if(n==1)return 0;  // Imp line, giving runtime error  
					   // // otherwise on Leetcode
	while(l<=r){		
		mid = l +(r-l)/2;
		if(mid>0 && mid <n-1){
			if(v[mid]>v[mid-1] && v[mid]>v[mid+1]){
				return mid;
			}
			else if(v[mid-1]>v[mid]){
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		else if(mid==0){
			if(v[0]>v[1]) return 0;
			
			return 1;
		}
		else{
			if(v[n-1]>v[n-2]) return n-1;

			return n-2;
		}
	}
	return -1;
}

void solve(){
std::vector<int> v={1,2,3,1};
int n=sz(v);
cout<<peak(v,n);

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