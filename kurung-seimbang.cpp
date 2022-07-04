#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    string a;
    getline(cin, a);
    stringstream ss(a);
    ss >> t;
    while(t--){
        stack<char> stk;
        int validity=1;
        string s;
        getline(cin, s);
        for(int i=0; i<s.size(); i++){
            if(stk.empty()){
                if(s[i]!='{'&&s[i]!='['&&s[i]!='('){
                    validity = 0;
                    break;
                }
                stk.push(s[i]);
            }else{
                if(s[i] == '{' || s[i] == '[' || s[i] == '('){
                    stk.push(s[i]);
                }else if(s[i] == '}'){
                    if(!stk.empty() && stk.top() == '{'){
                        stk.pop();
                    }else{
                        validity = 0;
                        break;
                    }
                }else if(s[i] == ']'){
                    if(!stk.empty() && stk.top() == '['){
                        stk.pop();
                    }else{
                        validity = 0;
                        break;
                    }
                }else if(s[i] == ')'){
                    if(!stk.empty() && stk.top() == '('){
                        stk.pop();
                    }else{
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
        if(validity == 1 && stk.empty()){
            cout << "1\n";
        }else{
            cout << "0\n";
        }
    }
}