#include <bits/stdc++.h>
#include <string>

class Vehicle
{
private:
    std::string modelName;
public:
    ~Vehicle()
    {
        std::cout << "Deleted a vehicle\n";
    }

    std::string getModelName()
    {
        return modelName;
    }

    void setModelName(std::string name)
    {
        modelName = name;
    }
};

class Taxi : public Vehicle
{
private:
    int kmCounter;
public:
    ~Taxi() // xóa ngược lại từ child class rồi đến parent class như stack
    {
        std::cout << "Deleted a taxi\n";
    }

    void start()
    {
        std::cout << "Started. Ready to run\n";
    }

};

int main()
{
    Taxi *taxi = new Taxi();   
    delete taxi;
    return 0;
}

