#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Abstract Class
class Compartment {
public:
    virtual string notice() = 0;
    virtual ~Compartment() {}
};

// Derived Classes
class FirstClass : public Compartment {
public:
    string notice() {
        return "First Class: Please maintain silence and keep your ticket ready.";
    }
};

class Ladies : public Compartment {
public:
    string notice() {
        return "Ladies Compartment: Reserved only for female passengers.";
    }
};

class General : public Compartment {
public:
    string notice() {
        return "General Compartment: Please do not overcrowd the compartment.";
    }
};

class Luggage : public Compartment {
public:
    string notice() {
        return "Luggage Compartment: Passengers are not allowed inside.";
    }
};

// Test Class
int main() {
    srand(time(0));

    Compartment *c[10];

    for (int i = 0; i < 10; i++) {
        int type = rand() % 4 + 1;

        if (type == 1)
            c[i] = new FirstClass();
        else if (type == 2)
            c[i] = new Ladies();
        else if (type == 3)
            c[i] = new General();
        else
            c[i] = new Luggage();
    }

    cout << "Compartment Notices:\n\n";

    for (int i = 0; i < 10; i++) {
        cout << "Compartment " << i + 1 << ": "
             << c[i]->notice() << endl;
    }

    // Free memory
    for (int i = 0; i < 10; i++) {
        delete c[i];
    }

    return 0;
}
