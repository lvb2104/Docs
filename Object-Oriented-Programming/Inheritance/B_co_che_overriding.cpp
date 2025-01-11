#include <bits/stdc++.h>
#include <string>

class Vehicle // Parent class/ Base class/ super class
{
private:
    std::string modelName;
    int version;
public:
    std::string getModelName()
    {
        return modelName;
    }

    void setModelName(std::string name)
    {
        modelName = name;
    }

    int getVersion()
    {
        return version;
    }

    void setVersion(int ver)
    {
        version = ver;
    }

    void run()
    {
        std::cout << "A vehicle is running ... !";
    }
};

class Taxi : public Vehicle // tức là class taxi kế thừa class vehicle, có hết tất cả
{
public: 
    void run()
    {
        Vehicle::run(); // bổ sung thêm thông tin từ parent class
        std::cout << "It's a taxi";
    }
};

class Truck : public Vehicle // Child Class/ Derived class/ Sub class
{

};

int main()
{
    // Vehicle *vehicle = new vehicle;
    Taxi *taxi = new Taxi;
    taxi->run();
    return 0;
}