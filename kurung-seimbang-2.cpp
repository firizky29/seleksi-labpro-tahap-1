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


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        stack<char> stk[3];
        int validity = 1;
        string s;
        cin >> s;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='{'){
                stk[0].push(s[i]);
            }
            else if(s[i]=='['){
                stk[1].push(s[i]);
            }
            else if(s[i]=='('){
                stk[2].push(s[i]);
            }
            else{
                if(s[i]=='}'){
                    if(!stk[0].empty()){
                        stk[0].pop();
                    }
                    else{
                        validity = 0;
                        break;
                    }
                }
                else if(s[i]==']'){
                    if(!stk[1].empty()){
                        stk[1].pop();
                    }
                    else{
                        validity = 0;
                        break;
                    }
                }
                else if(s[i]==')'){
                    if(!stk[2].empty()){
                        stk[2].pop();
                    }
                    else{
                        validity = 0;
                        break;
                    }
                }
                else{
                    validity = 0;
                    break;
                }
            }
        }
        for(int i=0; i<3&&validity; i++){
            if(!stk[i].empty()){
                validity = 0;
            }
        }
        if(validity == 1){
            cout << "1\n";
        }else{
            cout << "0\n";
        }
    }
}