#include <bits/stdc++.h>
#pragma GCC optimize ("03,unroll-loops")
#pragma GCC target ("avx2,bmi,bmi2")
using namespace std;
using ll = long long;
#define mod 1000000007
#define endl '\n'

bool check(int n){
    bool ok = false;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            int count = 0;
            while(n % i == 0){
                count++;
                n /= i;
            }
            if (count == 1){
                return 0;
            }
            if (count >= 2){
                ok = true;
            }
        }
    }
    if (n != 1) return false;
    return ok;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b; cin >> a >> b;
    for (int i = a; i <= b; i++){
        if (check(i)) cout << i << ' ';
    }
    return 0;
}