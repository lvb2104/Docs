#include <bits/stdc++.h>
#include <string>

class Vehicle
{
private: // chống việc sử dụng từ child class, chổng sử dụng từ bên ngoài
    std::string modelName;
public:
    std::string getModelName()
    {
        return modelName;
    }

    void setModelName(std::string name)
    {
        modelName = name;
    }

protected: // = private + public: chỉ cho child class sử dụng
    void run()
    {
        std::cout << "A vehicle is running ... !";
        
    }
};

class Taxi : public Vehicle // public la access modifier cua cac class (duoc) sau khi "inherit"
{
public:
    void start()
    {
        std::cout << "Started. Ready to run\n";
        run();
    }
};

int main()
{
    Taxi *taxi = new Taxi;
    taxi->start();
    return 0;
}