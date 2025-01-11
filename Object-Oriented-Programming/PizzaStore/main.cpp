#include "PizzaStore.h"

int main()
{
    PizzaStore *pizzaStore = new PizzaStore;
    pizzaStore->orderPizza("cheese");
    pizzaStore->orderPizza("pepperoni");
    pizzaStore->orderPizza("greek");
    pizzaStore->orderPizza("clam");
    return 0;
}