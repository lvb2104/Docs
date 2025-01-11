#ifndef PEPPERONIPIZZA_H
#define PEPPERONIPIZZA_H

#include "Pizza.h"

class PepperoniPizza : public Pizza
{
public:
    PepperoniPizza()
    {
        name = "Pepperoni Pizza";
        dough = "Regular Crust";
        sauce = "Marinara Pizza Sauce";
        toppings.push_back("Fresh Mozzarella");
        toppings.push_back("Parmesan");
        toppings.push_back("Pepperoni");
    }
};

#endif