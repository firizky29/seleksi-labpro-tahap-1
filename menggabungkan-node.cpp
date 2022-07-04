#include <bits/stdc++.h>

using namespace std;

#define FOR(a, b) for (int i = (int) a; i < (int) b; i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
const int mxn = 1e3+4;
const ll mod = 10;
int cnt[1001][1001];
void precompute(){  
    for(int i=0; i<=1000; i++){
        for(int j=0; j<=i; j++){
            if(j==0||i==j){
                cnt[i][j] = 1;
            }
            else{
                cnt[i][j] = (cnt[i-1][j-1]%mod+cnt[i-1][j]%mod)%mod;
            }
        }
    }
}
int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    precompute();
    ll ans = 0;
    int j=0;
    for(auto x: a){
        ans = (ans%mod+((cnt[n-1][j])%mod)*(x%mod))%mod;
        j++;
    }
    cout << ans << "\n";
    return 0;
}