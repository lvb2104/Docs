#ifndef PIZZASTORE_H
#define PIZZASTORE_H

#include "Pizza.h"
#include "CheesePizza.h"
#include "PepperoniPizza.h"
#include "GreekPizza.h"

class PizzaStore
{
public:
    void orderPizza(string type)
    {
        Pizza *pizza;
        pizza = createPizza(type);

        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();
    }

    virtual Pizza* createPizza(string type) = 0;
    // if (type == "cheese")
    // {
    //     pizza = new CheesePizza();
    // }
    // else if (type == "pepperoni")
    // {
    //     pizza = new PepperoniPizza;
    // }
    // else if (type == "greek")
    // {
    //     pizza = new GreekPizza;
    // }
    // else
    // {
    //     cout << "We don't have " + type << endl;
    //     return;
    // }
};

#endif