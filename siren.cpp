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
    int x1, x2;
    x1 = x2 = 0;
    for(int i=0; i<n; i++){
        if(i%2==0){
            if(s[i]=='1'){
                x1 ++;
            }
            else{
                x2++;
            }
        }
        else{
            if(s[i]=='0'){
                x1++;
            }
            else{
                x2++;
            }
        }
    }
    cout << min(x1, x2) << "\n";

    return 0;
}