#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;    
using namespace __gnu_pbds;

    #define ll                            long long
    #define int                           FO
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
    #define EPS 1e-9

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

// https://atcoder.jp/contests/arc132/tasks/arc132_c

    const ll M = 1e9 + 7;
    const ll MM = 998244353;
    const ll N = 5e5 + 7;

    bitset<5> bin(ll a){
        bitset<5> v(a);
        return v;
    }

    ll fun(ll i, ll mask, vi &v, vvi &dp, ll &d) {
        ll n = sz(dp);
            
        if(i >= n) return 1;

        if(dp[i][mask] != -1) return dp[i][mask]; 

        ll ans = 0;
        ll ind = -1;    
        

        for(ll j = i - d; j <= i + d; j++) {
            ind++;
            if(j < 0 || j >= n || v[i] != -1 && j != v[i]) continue;

            // cout << (mask & (1ll << ind));

            if((mask & (1ll << ind)) == 0){
                ll newmask = (mask | (1ll << ind));
                // trace(bin(mask));
                // trace(bin(newmask));

                if(i >= d && !(newmask & (1ll))){
                    continue;
                }
                newmask >>= 1;
                ans = (ans + fun(i+1, newmask, v, dp, d)) % MM;
            }
        }
        return dp[i][mask] = ans;

    }

    void solve() { 

        ll n; cin >> n;
        ll d; cin >> d;

        vi v(n);
        rep(i, 0, n){
            cin >> v[i];
            if(v[i] != -1) v[i]--;
        } 

        ll range = (2*d + 1);
        ll mask_size = (1ll << range);

        vvi dp(n, vi(mask_size, -1));

        ll mask = 0;
        ll ans = fun(0, mask, v, dp, d);
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