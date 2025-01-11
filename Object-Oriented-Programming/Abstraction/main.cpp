#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Woman {
private:
    float weight;
    float height;
    string fullname;
    int age;
public:
    Woman(){
        cout << "Create a new woman\n";
        fullname = "Unknown";
        age = 0;
    }

    Woman(string fn, int a, float w, float h){
        cout << "Create a new woman\n";
        fullname = fn;
        age = a;
        weight = w;
        height = h;
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

    float getWeight(){
        return weight;
    }

    float getHeight(){
        return height;
    }
};

class HealthChecker{
private:
    float weight;
    float height;
    int bloodPressure;
    int heartBeat;
public:
    void check(Woman *woman){
        weight = woman->getWeight();
        height = woman->getHeight();
        // ... calculate ...
        bloodPressure = 130; // getDevice()
        heartBeat = 80;
    }

    string getResult(){
        float bmi = weight / (height * height);
        if (bmi >= 18.5 && bmi <= 24.9
            && bloodPressure >= 120 && bloodPressure < 140
            && heartBeat >= 60 && heartBeat < 100
            ){
                return "Normal\n";
        }
        return "Abnormal\n";

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
    Woman *hariwon = new Woman("Hariwon", 35, 60, 1.65);
    HealthChecker *checker = new HealthChecker;
    checker->check(hariwon);
    string result = checker->getResult();
    cout << result;
    return 0;
}
