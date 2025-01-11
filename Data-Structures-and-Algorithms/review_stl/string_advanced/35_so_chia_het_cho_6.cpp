#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool chia2(string s){
    if ((s[s.size() - 1] - '0') % 2 == 0) return true;
    return false;
}

bool chia3(string s){
    ll sum = 0;
    for (char x : s) sum += (x - '0');
    if (sum % 3 == 0) return true;
    return false;
}

int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s; cin >> s;
    if (chia3(s) && chia2(s)) cout << "YES";
    else cout << "NO";
    return 0;
}