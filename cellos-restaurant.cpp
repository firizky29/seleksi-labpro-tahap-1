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
const int N = 1e5+5;
int n;
int a[N];

void add(int i, int val){
    for(;i<=n;i+=i&-i){
        a[i] += val;
    }
}

void addRange(int l, int r, int val){
    add(l, val);
    add(r+1, -val);
}

int get(int i){
    int ret = 0;
    for(;i>0;i-=i&-i){
        ret += a[i];
    }
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vector<int> ans;
    vector<int> v;
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        if(t==0){
            int x = get(v.size());
            addRange(v.size(), v.size(), -x);
            v.pop_back();
        }
        else if(t==1){
            int x;
            cin >> x;
            v.pb(x);
        }
        else{
            int y, x;
            cin >> y >> x;
            addRange(1, y, x);
        }
        if(v.size()==0){
            ans.pb(-1);
        }
        else{
            ans.pb(v.back()+get(v.size()));
        }
    }
    for(int i=0; i<n; i++){
        if(ans[i]==-1){
            cout << "EMPTY" << " \n"[i==n-1];
        }
        else{
            cout << ans[i] << " \n"[i==n-1];
        }
    }
    return 0;
}