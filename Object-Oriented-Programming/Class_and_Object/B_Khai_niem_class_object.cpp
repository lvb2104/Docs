#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// struct vẫn có access modifier phạm vi public private
// struct mặc định là public -> có thể truy cập từ bên ngoài
struct BodySize{
    vector<int> size3ring; 
    float weight;
};


// class thì mặc định là private -> không thể truy cập từ bên ngoài
class Woman {
public:
    string fullname; // biến thành viên member variable
    BodySize bodySize;

    void makeUp(){

    }

    void introduce(){ // hàm thành viên method
        age = 34;
        bodySize.weight = 45;
        cout << "Hi! I am a woman\n";
        cout << "I am " << age << " years old\n";
    }
private: // các thao tác ở bên ngoài sẽ không được, nhưng bên trong class thì vẫn được
    int age;
};

int main(){
    // Woman ngoc_trinh; // cấp phát tĩnh
    Woman *hariwon = new Woman; // cấp phát động
    hariwon->fullname = "Hariwon";
    hariwon->introduce();
    return 0;
}