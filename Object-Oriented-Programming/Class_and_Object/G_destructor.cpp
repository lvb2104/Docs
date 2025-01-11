#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Woman{
private:
    float weight;
public:
    string fullname;
    int age;

    Woman(){
        cout << "Created default a new woman\n";
        fullname = "Unknown";
        age = 0;
    }

    Woman(string fn, int a){
        cout << "Created a new woman\n";
        fullname = fn;
        age = a;
    }

    // destructor viết tường minh, chỉ có cấp phát động
    ~Woman(){
        cout << "Deleted a new woman\n";
    }

    void introduce(){
        cout << "Hi, my name is " << fullname << ".\n";
        cout << "I am " << age << " years old" << ".\n";
    }
};

void abc(){
    Woman somebody; // thoát ra khỏi scope thì nó sẽ bị xóa - gọi destructor
}

int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Woman *hariwon = new Woman("Hariwon", 35); // khai báo động thì k hủy thì nó tồn tại vv
    delete hariwon; // hàm destructor được gọi
    abc();
    return 0;
}