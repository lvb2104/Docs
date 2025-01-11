#include <iostream>

class Vehicle // interface = 1 class có tất cả function là pure virtual function
{
protected:
    std::string modelName;
public:
    virtual std::string getModelName() = 0;

    virtual void setModelName(std::string name) = 0;

    virtual void run() = 0;
};

class Car : public Vehicle
{
private:
    std::string ownerName;
public:
    Car()
    {
        std::cout << "Create a car ...\n";
    }
    void run() override
    {
        std::cout << "A car is running ... \n";
    }

    void setModelName(std::string name)
    {
        modelName = name;
    }

    std::string getModelName()
    {
        return modelName;
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

    void setModelName(std::string name)
    {
        modelName = name;
    }

    std::string getModelName()
    {
        return modelName;
    }
};

class Motorbike : public Vehicle
{
public:
    void run() override
    {
        std::cout << "A motorbike is running ...\n";
    }
    
    void setModelName(std::string name)
    {
        modelName = name;
    }

    std::string getModelName()
    {
        return modelName;
    }
};

int main()
{
    Vehicle *vehicleList[3];
    vehicleList[0] = new Car();
    vehicleList[1] = new Motorbike();
    vehicleList[2] = new Truck();
    for (int i = 0; i < 3; i++)
    {
        vehicleList[i]->run();
    }
    return 0;
}