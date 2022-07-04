#include <bits/stdc++.h>

using namespace std;

#define FOR(a, b) for (int i = (int) a; i < (int) b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int N = 1500000;
const int N2 = 2e5+5;
ll a[N2];
bool not_prime[N+1];
vector<int> pr;
int n, q;
void add(int i, ll val){
    for(;i<=n;i+=i&-i){
        a[i] += val;
    }
}

void addRange(int l, int r, ll val){
    add(l, val);
    add(r+1, -val);
}

ll get(int i){
    ll ret = 0LL;
    for(;i>0;i-=i&-i){
        ret += a[i];
    }
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    not_prime[0] = not_prime[1] = true;
    for (int i = 2; i * i <= N; i++) {
        if (!not_prime[i]) {
            for (int j = i * i; j <= N; j += i)
                not_prime[j] = true;
        }
    }
    for(int i=0; i<=N; i++){
        if(!not_prime[i]){
            pr.pb(i);
        }
    }

    for(int i=0; i<n; i++){
        ll x;
        cin >> x;
        addRange(i+1, i+1, x);   
    }
    while(q--){
        int t;
        cin >> t;
        if(t==1){
            int k;
            cin >> k;
            cout << get(k) << "\n";
        }
        else{
            int l, r, x;
            cin >> l >> r >> x;
            addRange(l, r, 1LL*pr[x-1]);
        }
    }

    return 0;
}