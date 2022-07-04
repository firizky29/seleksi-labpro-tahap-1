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
    int q;
    cin >> q;
    int fac[10];
    fac[0] = 1;
    fac[1] = 1;
    for(int i=2; i<=9; i++){
        fac[i] = fac[i-1]*i;
    }
    while(q--){
        int m, n;
        cin >> n >> m;
        string s = "";
        vector<int> st;
        for(int i=0; i<n; i++){
            st.pb(i+1);
        }

        m--;
        for(int i=n; i>0; i--){
            s += to_string(st[m/(fac[i-1])]);
            st.erase(st.begin()+(m/fac[i-1]));
            m = m%fac[i-1];
        }
        cout << s << "\n";
    }


    return 0;
}