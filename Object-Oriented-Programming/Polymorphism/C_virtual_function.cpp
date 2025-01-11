#include <iostream>

class Vehicle
{
private:
    std::string modelName;
public:
    Vehicle()
    {
        std::cout << "Create a vehicle ...\n";
    }

    std::string getModelName()
    {
        return modelName;
    }

    void setModelName(std::string name)
    {
        modelName = name;
    }

    virtual void run()
    {
        std::cout << "A vehicle is running ...\n";
    }
};

class Car : public Vehicle
{
private:
    std::string ownerName;
public:
    Car() // override
    {
        std::cout << "Create a car ...\n";
    }
    void run()
    {
        std::cout << "A car is running ... \n";
    }
};

class Truck : public Vehicle
{
private:
    int expirationYear;
public:
    Truck()
    {
        std::cout << "Create a truck ...\n";
    }
    void run() override
    {
        std::cout << "A truck is running ...\n";
    }
};

class Motorbike : public Vehicle
{
public:
    void run() override
    {
        std::cout << "A motorbike is running ...\n";
    }
};
// nếu không override thì gọi parent-class, còn có thì gọi ở child-class
int main()
{
    Vehicle *car = new Car(); // tạo car dùng pointer lưu 
    Vehicle *truck = new Truck();
    Vehicle *motorbike = new Motorbike();
    Vehicle *vehicleList[3];
    vehicleList[0] = car;
    vehicleList[1] = motorbike;
    vehicleList[2] = truck;
    for (int i = 0; i < 3; i++)
    {
        vehicleList[i]->run();
    }
    return 0;
}