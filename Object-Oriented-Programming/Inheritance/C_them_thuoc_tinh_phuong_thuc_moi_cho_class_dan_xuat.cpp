#include <bits/stdc++.h>
#include <string>

class Vehicle
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

class Taxi : public Vehicle
{
private:
    int kmCounter;
public: 
    void run()
    {
        Vehicle::run();
        std::cout << "It's a taxi";
    }

    void run(int km)
    {
        kmCounter = km;
    }

    int calculateFee()
    {
        return kmCounter * 10000;
    }
};

class Truck : public Vehicle
{

};

int main()
{

    Taxi *taxi = new Taxi;
    taxi->run(5);
    std::cout << "Fee: " << taxi->calculateFee() << "VND";
    return 0;
}