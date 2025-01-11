#ifndef GREEKPIZZA_H
#define GREEKPIZZA_H

#include "Pizza.h"

class GreekPizza : public Pizza 
{
public:
    GreekPizza()
    {
        name = "Greek Pizza";
        dough = "Thin Crust";
        sauce = "Olive Oil";
        toppings.push_back("Spinach");
        toppings.push_back("Kalamata Olives");
        toppings.push_back("Red Onion");
    }
};

#endif