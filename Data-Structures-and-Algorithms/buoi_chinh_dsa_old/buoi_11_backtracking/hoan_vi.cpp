#include <bits/stdc++.h>
#pragma GCC optimize("03,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2")
using namespace std;
using ll = long long;
#define mod 1000000007
#define endl '\n'

int x[100], n, used[100];

void in(){
    for (int i = 1; i <= n; i++){
        cout << x[i] << ' ';
    }
    cout << endl;
}

void Try(int i){
    for (int j = 1; j <= n; j++){
        if (used[j] == 0){
            x[i] = j;
            used[j] = 1;
            if (i == n){
                in();
            }
            else {
                Try(i + 1);
            }
            used[j] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    Try(1);
    return 0;
}