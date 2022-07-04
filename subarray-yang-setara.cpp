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
const int INF = 100000000;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<array<int, 3>> v (51, {0, INF, -1});
    int freq = 0;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        v[x][0]++;
        v[x][1] = min(v[x][1], i);
        v[x][2] = max(v[x][2], i);
        freq = max(freq, v[x][0]);
    }
    int ans = INF;
    for(int i=0; i<=50; i++){
        if(freq == v[i][0] && v[i][2]!=-1){
            ans = min(ans, v[i][2]-v[i][1]+1);
        }   
    }
    cout << ans << "\n";
    return 0;
}