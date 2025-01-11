#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool cmp(string a, string b){
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}

int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<string> a;
    string s;
    while(cin >> s){
        a.push_back(s);
    }
    sort(a.begin(), a.end(), cmp);
    for (string x : a){
        cout << x << ' ';
    }
    return 0;
}