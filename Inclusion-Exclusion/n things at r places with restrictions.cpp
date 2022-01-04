#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;    
using namespace __gnu_pbds;

    #define ll                            long long
    // #define int                           FO
    #define pb                            push_back
    #define ppb                           pop_back
    #define pf                            push_front
    #define ppf                           pop_front
    #define all(x)                        (x).begin(),(x).end()
    #define uniq(v)                       (v).erase(unique(all(v)),(v).end())
    #define sz(x)                         (ll)((x).size())
    #define fr                            first
    #define sc                            second
    #define pii                           pair<ll,ll>
    #define mkp                           make_pair
    #define rep(i,a,b)                    for(ll i=a;i<b;i++)
    #define rrep(i,a,b)                   for(ll i=a;i>=b;i--)
    #define REP(i,a,b)                    for(ll i=a;i<=b;i++)
    #define mem1(a)                       memset(a,-1,sizeof(a))
    #define mem0(a)                       memset(a,0,sizeof(a))
    #define ppc                           __builtin_popcount
    #define ppcll                         __builtin_popcountll
    #define acc                           accumulate
    #define endl                          '\n'
    #define length(a)                     sizeof(a)/sizeof(a[0])
    #define auv(v)                        for(auto &x:v) cout<<x<<' ';cout << endl;
    #define auvv(v)                       for(auto &x:v){for(auto &y:x)cout<<y<<' ';cout<<endl;}
    #define aump(mp)                      for(auto &x:mp) cout<<x.fr<<' '<<x.sc<<endl;  
    #define vi                            vector<ll>
    #define vvi                           vector<vector<ll>>
    #define vc                            vector<char>
    #define vvc                           vector<vector<char>>
    #define two(x)                        cout << x.fr << ' ' << x.sc << ' ';

    struct custom_hash {
        static uint64_t splitmix64(uint64_t x) {
            // http://xorshift.di.unimi.it/splitmix64.c
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
        }
        size_t operator()(uint64_t x) const {
            static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(x + FIXED_RANDOM);
        }
    };

    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        std::cerr << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }

    typedef tree<
    ll,
    null_type,
    less<ll>,  // less_equal<ll> for multiset
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;
    // find_by_order(k);    returs iterator of Kth element starting from 0;
    // order_of_key(k);     no of elemets strictly less than k;



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    #define EPS 1e-9
    const ll M = 1e9 + 7;
    const ll MM = 998244353;
    const ll N = 3e5 + 7;

// https://www.codechef.com/CDRV21B/problems/CNTARRAY
// this que boils down to no of permutations of putting n things in r places
// but with restriciton
    // : a no 'i' can not be placed at a specific pos 'j'

    int fact[N];
    int inv_fact[N];

    ll power(ll a, ll b) {
        if(b == 0) return 1;
        
        ll t = power(a, b/2);
        t = (t * t) % M;

        if(b & 1) t = (t * a) % M;

        return t;
    }

    void fun() {
        fact[0] = 1;
        rep(i, 1, N){
            fact[i] = (fact[i-1] * i) % M;
        }
        inv_fact[N-1] = power(fact[N-1], M - 2);
        rrep(i, N-2, 0) {
            inv_fact[i] = (inv_fact[i+1] * (i + 1)) % M;  
        }
    }
    
    ll ncr(ll n, ll r) {
        if(n < r || n < 0 || r < 0) return 0;

        ll ans = 1;
        ans = ((ans % M) * (fact[n] % M)) % M;
        ans = ((ans % M) * (inv_fact[n - r] % M)) % M;
        ans = ((ans % M) * (inv_fact[r] % M)) % M;
        
        return ans;
    }

    void solve(){
        fun();
        
        ll n, m; cin >> n >> m;

        vi v(n);
        ll cnt = 0;
        
        rep(i, 0, n) {
            cin >> v[i];
            if(v[i] <= m) cnt++;
        }

// total possible permutations without restriction
        ll ans = ((ncr(m, n)) * (fact[n])) % M;

// this will be the total no of permutations with restrictions 
// reducing this from 'ans' will give the result
        ll ded = 0;

// using inclusion exclusion priciple
// S(A∪B∪C)=S(A)+S(B)+S(C)−S(A∩B)−S(A∩C)−S(B∩C)+S(A∩B∩C)

        rep(z, 1, cnt + 1){
            ll ele = ncr(cnt, z);
            ll avl = m - z; 
            ll pos = n - z;
            ll temp = ncr(avl, pos);
        
            temp = (temp % M * fact[pos] % M) % M;
            temp = (temp % M * ele % M) % M;
            
            if(z % 2) 
                ded = (ded + temp) % M;    
            else
                ded = (ded - temp + M) % M;
        }
        // trace(ded);
        ans = (ans - ded + M) % M;

        cout << ans;
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
            
            cerr << setprecision(15) << fixed;
            cout << setprecision(15) << fixed;

            
            ll t = 1;
            // cin >> t;
            while(t--) {
                solve();
                cout << endl;
            } 
            return 0;
        }   