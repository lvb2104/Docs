#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Student{
private:
    int codeStudent;
    string name;
    int age;
    string hometown;
    float height, weight;
    vector<float> point;
public:
    Student(int m, string n, int a, string h, float he, float w, vector<float> p){
        codeStudent = m;
        name = n;
        age = a;
        hometown = h;
        height = he;
        weight = w;
        for (int i = 0; i < 8; i++){
            point.push_back(p[i]);
        }
    }
    void introduce();
    int getCodeStudent();
};

class Class{
private:
    string classCode;
    vector<Student> students;
    Student *monitor;
    int amountOfClass;
public:
    Class(string c, Student a, int am){
        classCode = c;
        students.push_back(a);
        amountOfClass = am;
    }
    void printInfo();
    void addAStudent(Student a);
    void removeAStudent(int codeStudent);
};

void Class::printInfo(){
    cout << "So lop hoc trong truong: " << amountOfClass << endl;
    cout << "Lop " << classCode << " gom cac thanh vien sau: " << endl;
    for (Student x : students){
        x.introduce();
    }
}

int Student::getCodeStudent(){
    return codeStudent;
}

void Class::addAStudent(Student a){
    students.push_back(a);
}

void Class::removeAStudent(int codeStudent){
    auto it = students.begin();
    for (; it != students.end(); it++){
        if (it->getCodeStudent() == codeStudent){
            break;
        }
    }
    students.erase(it);
}

string hocLuc(vector<float> point){
    float total = 0;
    for (float x : point){
        total += x;
    }
    float dtb = total / 8;
    if (dtb >= 8) return "Gioi";
    else if (dtb < 8 && dtb >= 5) return "Kha";
    else {
        return "TB";
    }
}

void Student::introduce(){
    cout << name << " - " << age << " - " << hometown << endl;
    cout << "Toan: " << point[0] << endl;
    cout << "Ly: " << point[1] << endl;
    cout << "Hoa: " << point[2] << endl;
    cout << "Van: " << point[3] << endl;
    cout << "Anh: " << point[4] << endl;
    cout << "Sinh: " << point[5] << endl;
    cout << "Su: " << point[6] << endl;
    cout << "Dia: " << point[7] << endl;
    cout << "Hoc luc: " << hocLuc(point) << endl;
}

int main(){
    Student *tui = new Student(23520112, "Le_Van_Bao", 18, "Hai_Duong", 170, 70, {9, 8, 7, 6, 5, 10, 9, 8});
    Class *loptui = new Class("10A5", *tui, 1);
    loptui->printInfo();
    cout << endl;
    Student *Long = new Student(23520113, "Bui_Ngoc_Long", 18, "TPHCM", 170, 70, {9, 8, 7, 6, 5, 10, 9, 8});
    loptui->addAStudent(*Long);
    loptui->printInfo();
    cout << endl;
    loptui->removeAStudent(23520112);
    loptui->printInfo();
    return 0;
}