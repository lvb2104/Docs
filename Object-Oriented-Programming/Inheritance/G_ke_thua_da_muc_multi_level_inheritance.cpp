#include <bits/stdc++.h>
#include <string>

class Vehicle
{
private:
    std::string modelName;
public:
    Vehicle()
    {
        std::cout << "Creating a vehicle ... !\n";
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
        std::cout << "A vehicle is running ... !";
    }
};

class Car : public Vehicle
{
private:
    std::string ownerName;
public:
    Car()
    {
        std::cout << "Creating a car ... !\n";
    }
};

class Taxi : public Car
{
public:
    Taxi()
    {
        std::cout << "Creating a taxi ... !\n";
    }
};

int main()
{
    Taxi *taxi = new Taxi; // gọi lần lượt các constructor từ Vehicle -> Car -> Taxi
    // taxi->run();
    return 0;
}