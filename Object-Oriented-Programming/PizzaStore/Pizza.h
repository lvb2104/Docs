#ifndef PIZZA_H
#define PIZZA_H

#include <bits/stdc++.h>
using namespace std;

class Pizza 
{
protected:
    string name;
    string dough;
    string sauce;
    vector<string> toppings;
public:
    void prepare()
    {
        cout << "Preparing " + name << endl;
        cout << "Tossing dough ..." << endl;
        cout << "Adding sauce ..." << endl;
        cout << "Adding toppings: ";
        for (string topping : toppings)
        {
            cout << "\t" + topping;
        }
        cout << endl;
    }

    void bake()
    {
        cout << "Baking " + name + " in 30 minutes" << endl;
    }

    void cut()
    {
        cout << "Cutting " + name << endl;
    }

    void box()
    {
        cout << "Boxing " + name << endl;
    }
};

#endif