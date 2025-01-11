#include <bits/stdc++.h>
#include <string>

class Vehicle
{
private:
    std::string modelName;
public:
    // Vehicle()
    // {
    //     std::cout << "Created a vehicle\n";
    // }

    Vehicle(std::string name)
    {
        modelName = name;
        std::cout << "Created a vehicle with name " << modelName << '\n';
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
    Taxi(std::string name) : Vehicle(name)// -> tìm hàm khởi tạo default của parent class nếu k gọi ...
    {
        std::cout << "Created a taxi\n";
    }

    void start()
    {
        std::cout << "Started. Ready to run\n";
    }
};

int main()
{
    Taxi *taxi = new Taxi("Kia morning"); // taxi có quan hệ kế thừa với vehicle -> khởi tạo parent class trước
    // -> sau đó khởi tạo các hàm riêng của child class -> parent class + bonus = child class
    Taxi *taxi1 = new Taxi("Vinfast Fadil");
    return 0;
}