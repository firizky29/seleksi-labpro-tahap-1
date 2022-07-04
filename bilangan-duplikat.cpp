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

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int ans;
    vector<int> v(n, 0);
    for(int i=0; i<=n; i++){
        int x;
        cin >> x;
        if(v[x-1]){
            ans = x;
        }
        v[x-1] = 1;
    }
    cout << ans << "\n";
    return 0;
}