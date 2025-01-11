#include <bits/stdc++.h>

class FlightTicket
{
    private:
        std::string FlightName;
        int FlyTime;
        int Price;
};

class Person
{
    private:
        std::string Name;
        std::string Gender;
        int Age;
};

class Passenger : public Person
{
    private:
        int numberOfTickets;
        FlightTicket *flightTicket = new FlightTicket[numberOfTickets];
};

int main()
{
    
    return 0;
}