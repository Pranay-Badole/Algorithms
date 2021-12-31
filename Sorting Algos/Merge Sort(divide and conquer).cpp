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
	#define REP(i,a,b)        for(int i=a;i<=b;i++)
	#define mem1(a)           memset(a,-1,sizeof(a))
	#define mem0(a)           memset(a,0,sizeof(a))
	#define ppc               __builtin_popcount
	#define ppcll             __builtin_popcountll
	#define acc				  accumulate
	#define endl			  '\n'
	#define auv(v)		      for(auto x:v) cout<<x<<' '; 
	#define aump(mp)	      for(auto x:mp) cout<<x.fr<<' '<<x.sc<<endl; 
	
const int N = 2e3+5;	

	void Merge(int arr[0],int start,int mid,int end){
		int temp[end-start+1];
		int i=start,j=mid+1,t=0;
		while(i<=mid && j<=end){
			if(arr[i]<arr[j]){
				temp[t]=arr[i];
				i++;
			}
			else{
				temp[t]=arr[j];
				j++;	
			}
			t++;
		}
		while(i<=mid){temp[t]=arr[i];i++;t++;}
		while(j<=end){temp[t]=arr[j];j++;t++;}

		REP(i,start,end){
			arr[i]=temp[i-start];
		}
	}
	void Merge_sort(int a[], int i, int j){
		if(i<j){
			int mid=(i+j)/2;
			Merge_sort(a,i,mid);
			Merge_sort(a,mid+1,j);
			Merge(a,i,mid,j);
		}
	}

	void solve(){
		int a[6]={5, 1, 6, 2, 4, 3};

		Merge_sort(a,0,5);
		auv(a);
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