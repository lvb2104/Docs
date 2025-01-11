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

    void run()
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
        ownerName = "None";
    }
    void run()
    {
        std::cout << "A car of " << ownerName << "  is running ... \n";
    }
};

class Truck
{

};

int main()
{
    // Car *car = new Car;
    // ((Vehicle*)car)->run(); // up-casting
    // Vehicle* vehicle = new Vehicle();
    // ((Car*)vehicle)->run(); // down-casting, ép xuống không có nghĩa là sẽ có property của child-class
    Car *car = new Car(); // tạo bộ nhớ cấp phát động ở heap
    Vehicle *vehicle = car; // gán địa chỉ của car cho vehicle, ngầm định casting
    ((Car*)vehicle)->run(); // down-casting

    return 0;
}