#include <bits/stdc++.h>

using namespace std;

#define FOR(a, b) for (int i = (int) a; i < (int) b; i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
const int mxn = 1e2+5;
vector<pii> adj[mxn][mxn];
queue<pii> q;
int used[mxn][mxn];
int c[mxn][mxn];
int cnt;
void bfs(pii s){
    q.push(s);
    used[s.first][s.second] = 1;
    c[s.first][s.second] = cnt;
    while (!q.empty()) {
        pii v = q.front();
        q.pop();
        for (auto u : adj[v.first][v.second]) {
            if (used[u.first][u.second]==-1) {
                used[u.first][u.second] = 1;
                c[u.first][u.second] = cnt;
                q.push(u);
            }
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    cnt = 0;
    int dx[] = {1,-1,0,0};
    int dy[] = {0, 0, 1,-1};
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> c[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<4&&c[i][j]==1; k++){
                int x = i+dx[k];
                int y = j+dy[k];
                if(x<0||y<0||x>N-1||y>N-1||c[x][y]!=1) continue;
                adj[i][j].pb({x, y});
            }
        }
    }
    memset(used, -1, sizeof(used));

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(c[i][j]==1){
                //cout << used[i][j];
                if(used[i][j]==-1&&c[i][j]==1){
                    cnt ++;
                    bfs({i, j});
                    //cout << used[i][j] << "\n";
                }
            }
        }
    }
    if(cnt==1){
        cout << 0 << "\n";
    }
    else{
        int mnx1, mxx1, mny1, mxy1;
        int mnx2, mxx2, mny2, mxy2;
        mnx1 = mnx2 = mny1 = mny2 = 101;
        mxx1 = mxx2 = mxy1 = mxy2 = -1;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(c[i][j]==1){
                    mnx1 = min(i, mnx1);
                    mny1 = min(j, mny1);
                    mxx1 = max(i, mxx1);
                    mxy1 = max(j, mxy1);
                }
                else if(c[i][j]==2){
                    mnx2 = min(i, mnx2);
                    mny2 = min(j, mny2);
                    mxx2 = max(i, mxx2);
                    mxy2 = max(j, mxy2);
                }
            }
        }

        vector<pii> v1, v2;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(c[i][j]==1&&(i==mnx1 || i==mxx1 || j==mny1 || j==mxy1)){
                    v1.pb({i, j});
                }
                if(c[i][j]==2&&(i==mnx2 || i==mxx2 || j==mny2 || j==mxy2)){
                    v2.pb({i, j});
                }
            }
        }
        int ans = 100*100+4;
        for(auto p1: v1){
            for(auto p2: v2){
                ans = min((int)abs(p1.first-p2.first)+(int)abs(p1.second-p2.second)-1, ans);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}