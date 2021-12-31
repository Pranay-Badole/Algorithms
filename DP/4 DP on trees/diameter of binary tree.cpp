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
	#define auv(v)		      for(auto x:v) cout<<x<<' '; cout<<endl;
	#define auvv(v)			  for(auto x:v){for(auto y:x)cout<<y<<' ';cout<<endl;}
	#define aump(mp)	      for(auto x:mp) cout<<x.fr<<' '<<x.sc<<endl; 
	
 
const int N=1e5+5;
const int M=100000000;

class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int a){
		data = a;
		left = NULL;
		right  = NULL;
	}
};

Node *root  = new Node(2);

int height(Node* root){
	if(root == NULL) return 0;

	return  1 + max(height(root->left),height(root->right));
}


int diameter(Node* root){
	if(root==NULL){
		return 0;
	}
	Node * lt = root->left;
	Node * rt = root->right; 
	
	int lh = height(lt);
	int rh = height(rt);

	int left =  diameter(lt);
	int right = diameter(rt);

	int a1 = lh + rh + 1;
	int ans = max(a1,max(left,right));

	return ans;
}


//	using changes in the code of the height function()

int diameter_optimized(Node * root, int & res){
	if(!root) return 0;

	int left = diameter_optimized(root->left, res);
	int right = diameter_optimized(root->right, res);

	int temp = 1 + max(left, right);

	int ans = 1 + left + right;
	res = max(res,max(temp,ans));
	return temp;
	// this returns the height of the current node
}

void solve(){
	
	root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(3);
    root->right->right = new Node(6);
    root->left->right->right = new Node(4);
    root->right->right->right = new Node(7);
    root->right->right->right->left = new Node(8);
    root->right->right->right->left->right= new Node(9);

    cout << diameter(root) << endl;

    int res = INT_MIN;
    diameter_optimized(root, res);
    cout << res;

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