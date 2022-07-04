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
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> oset;
const int mxn = 1e4+2;
int a[mxn];
pii va[mxn];
vector<int> t[4*mxn];
int n, q;

void build(int v, int tl, int tr){
    if(tl==tr){
        t[v].pb(va[tl].se);
    } else{
        int mid = (tl + tr)/2;
        build(2*v, tl, mid);
        build(2*v+1, mid+1, tr);
        merge(t[2*v].begin(), t[2*v].end(), t[2*v+1].begin(), t[2*v+1].end(), back_inserter(t[v]));
    }
}


int ans(int v, int tl, int tr, int l, int r, int k){
    if(tl==tr){
        return t[v].back(); 
    } 
    int mid = (tl+tr)/2;
    int x = upper_bound(t[2*v].begin(), t[2*v].end(), r) - lower_bound(t[2*v].begin(), t[2*v].end(), l);
    if(x >= k){
        return ans(2*v, tl, mid, l, r, k);
    } else{
        return ans(2*v+1, mid+1, tr, l, r, k-x);
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        va[i] = {a[i], i};
    }
    sort(va, va+n);
    build(1, 0, n-1);
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << a[ans(1, 0, n-1, l-1, r-1, (r-l+2)/2)] << "\n";
    }
    
    return 0;
}