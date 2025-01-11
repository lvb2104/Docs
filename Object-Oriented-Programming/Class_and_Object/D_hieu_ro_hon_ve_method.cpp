#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Message { // đơn giản thì nên đặt là struct
public:
    string content;
    string sender;
};

class Woman {
public:
    string fullname;
    int age;

    Message *introduce(string language, bool isFull = true){ // giá trị mặc định phải ở sau
        Message *msg = new Message; // nên cấp phát động vì có nhiều dối tượng
        if (language == "Vietnam"){
            msg->content = "Xin chao ! Toi la phu nu\n";
            if (isFull){
                msg->content += "Toi rat xjnh dep\n";
            }
        }
        else {
            msg->content = "Hi ! I am woman\n";
            if (isFull){
                msg->content += "I am very beautiful\n";
            }
        }
        return msg;
    }

private:
    float weight;
};

int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Woman *hariwon = new Woman;
    Message *msg = hariwon->introduce("Vietnam"); // vì khi không muốn sử dụng gtrị mặc định thì k được nhập
    cout << msg->content << endl;
    return 0;
}