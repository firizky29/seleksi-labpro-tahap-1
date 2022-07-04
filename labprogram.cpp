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
    string s;
    cin >> s;
    int n = s.size();
    ll L, A, B, P, R, O, G, M;
    L = A = B = P = R = O = G = M = 0LL; 
    for(int i=0; i<n; i++){
        if(s[i]=='L'){
            L++;
        }
        else if(s[i]=='A'){
            A++;
        }
        else if(s[i]=='B'){
            B++;
        }
        else if(s[i]=='P'){
            P++;
        }
        else if(s[i]=='R'){
            R++;
        }
        else if(s[i]=='O'){
            O++;
        }
        else if(s[i]=='G'){
            G++;
        }
        else if(s[i]=='M'){
            M++;
        }
    }
    ll ans = 0;
    ans = min(L, min(A/2, min(B, min(P, min(R/2, min(O, min(G, M)))))));
    cout << ans << "\n";
    return 0;
}