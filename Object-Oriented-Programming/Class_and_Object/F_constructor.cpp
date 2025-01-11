#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Woman{
private:
    float weight;
public:
    string fullname;
    int age;

    // constructor vẫn có tham số như function thường
    Woman(){ // khởi tạo giá trị ban đầu để tránh việc biến chứa gtrị rác
        cout << "Create a new woman\n";
        fullname = "Unknown";
        age = 0;
    }

    Woman(string fn, int a){ // overloading function
        cout << "Create a new woman\n";
        fullname = fn;
        age = a;
    }

    void introduce(){
        cout << "Hi, my name is " << fullname << ".\n";
        cout << "I am " << age << " years old" << ".\n";
    }
};

int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Woman *hariwon = new Woman("Hariwon", 35);
    hariwon->introduce();
    Woman *ngoctrinh = new Woman("Ngoc Trinh", 29);
    ngoctrinh->introduce();
    Woman *kkk = new Woman;
    kkk->introduce();
    return 0;
}