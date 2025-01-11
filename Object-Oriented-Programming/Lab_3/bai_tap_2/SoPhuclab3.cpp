#include "SoPhuclab3.h"

SoPhuc operator+(const SoPhuc &lhs, const SoPhuc &rhs)
{
    SoPhuc result;
    result.dThuc = lhs.dThuc + rhs.dThuc;
    result.dAo = lhs.dAo + rhs.dAo;
    return result;
}

SoPhuc operator-(const SoPhuc &lhs, const SoPhuc &rhs)
{
    SoPhuc result;
    result.dThuc = lhs.dThuc - rhs.dThuc;
    result.dAo = lhs.dAo - rhs.dAo;
    return result;
}

SoPhuc operator*(const SoPhuc &lhs, const SoPhuc &rhs)
{
    SoPhuc result;
    result.dThuc = lhs.dThuc * rhs.dThuc - lhs.dAo * rhs.dAo;
    result.dAo = lhs.dThuc * rhs.dAo + lhs.dAo * rhs.dThuc;
    return result;
}

SoPhuc operator/(const SoPhuc &lhs, const SoPhuc &rhs)
{
    SoPhuc result;
    int divisor = rhs.dThuc * rhs.dThuc + rhs.dAo * rhs.dAo;
    result.dThuc = (lhs.dThuc * rhs.dThuc + lhs.dAo * rhs.dAo) / divisor;
    result.dAo = (lhs.dAo * rhs.dThuc - lhs.dThuc * rhs.dAo) / divisor;
    return result;
}

bool operator==(const SoPhuc &lhs, const SoPhuc &rhs)
{
    return (lhs.dThuc == rhs.dThuc) && (lhs.dAo == rhs.dAo);
}

bool operator!=(const SoPhuc &lhs, const SoPhuc &rhs)
{
    return !(lhs == rhs);
}

std::istream &operator>>(std::istream &is, SoPhuc &s)
{
    is >> s.dThuc >> s.dAo;
    return is;
}

std::ostream &operator<<(std::ostream &os, const SoPhuc &s)
{
    os << s.dThuc << " + " << s.dAo << "i";
    return os;
}