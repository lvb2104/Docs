#include <bits/stdc++.h>

class SmartPhone
{
    private:
        std::string brand;
        std::string model;
        float size;
        int expireYear;
    public:
        void startUp()
        {
            std::cout << "Starting up ... !\n";
        }
        
        void phoneCall()
        {
            std::cout << "Calling ... !\n";
        }
};

class GalaxyS : public SmartPhone
{
    public:
        void openSPen()
        {
            std::cout << "Opening S Pen ... !\n";
        }

        void openGooglePlay()
        {
            std::cout << "Opening Google Play ... !\n";
        }
};

class Iphone : public SmartPhone
{
    public:
        void openAppStore()
        {
            std::cout << "Opening App Store ... !\n";
        }

        void faceId()
        {
            std::cout << "Face ID ... !\n";
        }

        void fileTransferAirDrop()
        {
            std::cout << "File transfer AirDrop ... !\n";
        }
};

int main()
{
    
    return 0;
}