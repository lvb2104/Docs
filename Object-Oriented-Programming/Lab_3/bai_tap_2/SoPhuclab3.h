#ifndef SOPHUC_OPERATOR
#define SOPHUC_OEPRATOR

#include <iostream>
using namespace std;

class SoPhuc
{
private:
    double dThuc, dAo;

public:
    // Default constructor
    SoPhuc()
    {
        dThuc = 0;
        dAo = 0;
    }
    // Parameterized constructor
    SoPhuc(int thuc, int ao)
    {
        dThuc = thuc;
        dAo = ao;
    }

    // Additional operators

    friend SoPhuc operator+(const SoPhuc &lhs, const SoPhuc &rhs);
    friend SoPhuc operator-(const SoPhuc &lhs, const SoPhuc &rhs);
    friend SoPhuc operator*(const SoPhuc &lhs, const SoPhuc &rhs);
    friend SoPhuc operator/(const SoPhuc &lhs, const SoPhuc &rhs);
    friend bool operator==(const SoPhuc &lhs, const SoPhuc &rhs);
    friend bool operator!=(const SoPhuc &lhs, const SoPhuc &rhs);
    friend std::istream &operator>>(std::istream &is, SoPhuc &s);
    friend std::ostream &operator<<(std::ostream &os, const SoPhuc &s);
};

#endif
