#include <bits/stdc++.h>
#include <string>

class Vehicle
{
private:
    std::string modelName;
public:
    Vehicle()
    {
        // std::cout << "Creating a vehicle ... !\n";
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

class House
{
private:
    float area;
public:
    void setArea(float a)
    {
        area = a;
    }

    float getArea()
    {
        return area;
    }
};

class MobiHome : public Vehicle, public House // multi inheritance
{

};

class Car : public Vehicle
{

};

class Taxi : public Car
{

};

int main()
{
    MobiHome *mobiHome = new MobiHome;
    mobiHome->run();
    mobiHome->setArea(100.0);
    std::cout << mobiHome->getArea();
    return 0;
}