#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int sum = 0;
    for (int i = 0; i < s.size(); i++){
        if (isdigit(s[i])){
            sum += s[i] - '0';
        }
    }
    cout << sum;
    return 0;
}