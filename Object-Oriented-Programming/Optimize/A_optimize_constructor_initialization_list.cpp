#include <iostream>
#include <string>
#include <vector>

class Vehicle
{
protected:
    const std::string modelName;
    int manufactureYear;
public:
    Vehicle(std::string name, int year)
    {
        modelName = name;
        manufactureYear = year;
    }
};

class Taxi
{
private:
    int kmCounter;
public:
    Taxi(std::string name, int year) : Vehicle(name, year)
    {

    }

    void run() override
    {
        std::cout << "A car is running ...\n";
    }
};

int main()
{
    Taxi *taxi = new Taxi("Kia Morning", 2022);
    
    return 0;
}