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

struct pt {
    ll x, y;
};

struct seg {
    pt p, q;
    int id;

    double get_y(ll x) const {
        if(p.x == q.x)
            return p.y;
        return p.y + (q.y - p.y) * (x - p.x) / (q.x - p.x);
    }
};

bool intersect1d(ll l1, ll r1, ll l2, ll r2) {
    if (l1 > r1)
        swap(l1, r1);
    if (l2 > r2)
        swap(l2, r2);
    return max(l1, l2) <= min(r1, r2);
}

int vec(const pt& a, const pt& b, const pt& c) {
    double s = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    return s == 0 ? 0 : s > 0 ? +1 : -1;
}

bool intersect(const seg& a, const seg& b)
{
    return intersect1d(a.p.x, a.q.x, b.p.x, b.q.x) &&
           intersect1d(a.p.y, a.q.y, b.p.y, b.q.y) &&
           vec(a.p, a.q, b.p) * vec(a.p, a.q, b.q) <= 0 &&
           vec(b.p, b.q, a.p) * vec(b.p, b.q, a.q) <= 0;
}

bool operator<(const seg& a, const seg& b)
{
    ll x = max(min(a.p.x, a.q.x), min(b.p.x, b.q.x));
    return a.get_y(x) < b.get_y(x);
}

struct event {
    ll x;
    int tp, id;

    event() {}
    event(ll x, int tp, int id) : x(x), tp(tp), id(id) {}

    bool operator<(const event& e) const {
        if (x != e.x) 
            return x < e.x;
        return tp > e.tp;
    }
};

set<seg> s;
vector<set<seg>::iterator> where;

set<seg>::iterator prev(set<seg>::iterator it) {
    return it == s.begin() ? s.end() : --it;
}

set<seg>::iterator next(set<seg>::iterator it) {
    return ++it;
}

pair<int, int> solve(const vector<seg>& a) {
    int n = (int)a.size();
    vector<event> e;
    for (int i = 0; i < n; ++i) {
        e.push_back(event(min(a[i].p.x, a[i].q.x), +1, i));
        e.push_back(event(max(a[i].p.x, a[i].q.x), -1, i));
    }
    sort(e.begin(), e.end());

    s.clear();
    where.resize(a.size());
    for (size_t i = 0; i < e.size(); ++i) {
        int id = e[i].id;
        if (e[i].tp == +1) {
            set<seg>::iterator nxt = s.lower_bound(a[id]), prv = prev(nxt);
            if (nxt != s.end() && intersect(*nxt, a[id]))
                return make_pair(nxt->id, id);
            if (prv != s.end() && intersect(*prv, a[id]))
                return make_pair(prv->id, id);
            where[id] = s.insert(nxt, a[id]);
        } else {
            set<seg>::iterator nxt = next(where[id]), prv = prev(where[id]);
            if (nxt != s.end() && prv != s.end() && intersect(*nxt, *prv))
                return make_pair(prv->id, nxt->id);
            s.erase(where[id]);
        }
    }

    return make_pair(-1, -1);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    ll ans = 0;
    vector<pair<char, ll>> inp;
    vector<int> x (n, 0);
    vector<int> y (n, 0);
    int l, r;
    r = n-1; l = 0;
    int prefX, prefY, curX, curY;
    prefX = prefY = curX = curY = 0;
    vector<ll> pref(n, 0);
    vector<seg> p;
    for(int i=0; i<n; i++){
        char d;
        ll t;
        cin >> d >> t;
        if(d=='W'){
            x[i]--;
        } else if(d=='N'){
            y[i]++;
        } else if(d=='E'){
            x[i]++;
        } else{
            y[i]--;
        }
        inp.pb({d, t});
        if(i>0&&(x[i]*x[i-1]<0)||(y[i]*y[i-1]<0)){
            r = min(r, i);
        }
        curX = prefX + (t-1)*x[i];
        curY = prefY + (t-1)*y[i];
        p.pb({{prefX, prefY}, {curX, curY}, i});
        prefX = curX + x[i];
        prefY = curY + y[i];
        pref[i] = (i>0?pref[i-1]:0) + t;
    }
    int id = 0;
    while(l <= r){
        int mid = (l+r)/2;
        vector<seg> tmp (p.begin(), p.begin()+mid);
        pair<ll, ll> pl = solve(tmp);
        if(pl.first==-1&&pl.second==-1){
            l = mid+1;
            id = mid;
        } else{
            r = mid-1;
        }
    }
    if(id && (x[id]*x[id-1]==-1||y[id]*y[id-1]==-1)){
        cout << pref[id-1] << "\n";
    } else if(id==0){
        cout << pref[0] << "\n";
    } else{
        ll l1 = 1, r1 = inp[id].second;
        curX = p[id].p.x;
        curY = p[id].p.y;
        vector<seg> tmp(p.begin(), p.begin()+id-1);
        while(l1<=r1){
            ll mid = (l1+r1)/2;
            tmp.pb({{curX, curY}, {curX + mid*x[id], curY + mid*y[id]}, id});
            pair<ll, ll> pl = solve(tmp);
            if(pl.first==-1&&pl.second==-1){
                l1 = mid+1;
                ans = mid;
            } else{
                r1 = mid-1;
            }
            tmp.pop_back();
        }
        cout << pref[id-1] + ans + 1 << "\n";
    }
    return 0;
}