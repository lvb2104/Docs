#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Woman{
private:
    float weight;
    string fullname;
    int age;
public:
    Woman(){
        cout << "Create a new woman\n";
        fullname = "Unknown";
        age = 0;
    }

    Woman(string fn, int a){
        cout << "Create a new woman\n";
        fullname = fn;
        age = a;
    }

    void introduce(){
        cout << "Hi, my name is " << fullname << ".\n";
        cout << "I am " << age << " years old" << ".\n";
    }

    void setAge(int a){
        age = a;
    }

    int getAge(){
        return age;
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
    hariwon->setAge(36);
    cout << hariwon->getAge();
    return 0;
}