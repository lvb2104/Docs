#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Woman{
private:
    float weight;
public:
    static void what(){ // không phụ thuộc vào object, nếu sử dụng các biến của class k static thì sẽ lỗi
        cout << "Woman is to be love\n";
        cout << "There are " << numberOfWoman << " woman in program now\n";
    }
    static int numberOfWoman; // ra ngoài global để initial, giống global variable nhưng gắn liền class

    string fullname;
    int age;

    Woman(){
        cout << "Create a new woman\n";
        fullname = "Unknown";
        age = 0;
    }

    Woman(string fn, int a){
        cout << "Create a new woman\n";
        fullname = fn;
        age = a;
        numberOfWoman++;
    }

    void introduce(){
        cout << "Hi, my name is " << fullname << ".\n";
        cout << "I am " << age << " years old" << ".\n";
    }
};

int Woman::numberOfWoman = 0; // initial ở đây, tương tự như global variable

int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // Woman::what(); // gọi static không phụ thuộc vào class
    // Woman *hariwon = new Woman("Hariwon", 35);
    // hariwon->what(); // gọi bthg

    // cout << Woman::numberOfWoman << endl; // gọi giống static function
    Woman::what();
    return 0;
}