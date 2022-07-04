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
const int INF = 1e8;
int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    vector<array<int, 3>> e(51, {0, INF, -1});
    for(int i=0; i<n; i++){
        cin >> a[i];
        e[a[i]][0]++;
        e[a[i]][1] = min(e[a[i]][1], i);
        e[a[i]][2] = max(e[a[i]][2], i);
    }
    bool ans = false;
    for(int i=1; i<=50; i++){
        if(e[i][0]>=2){
            if(e[i][2]-e[i][1]>1){
                ans = true;
                break;
            }
        }
    }
    if(ans){
        cout << "Y\n";
    }
    else{
        cout << "N\n";
    }

    return 0;
}