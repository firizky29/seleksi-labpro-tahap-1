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


ll xorsum(ll n){
    if(n%4==0){
        return n;
    } else if(n%4==1){
        return 1;
    } else if(n%4==2){
        return n+1;
    } else{
        return 0;
    }
}
int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll l, r;
        cin >> l >> r;
        cout << (xorsum(r)^xorsum(l-1)) << "\n";
    }

    return 0;
}