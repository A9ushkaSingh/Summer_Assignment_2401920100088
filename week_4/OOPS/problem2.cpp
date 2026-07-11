#include <iostream>
using namespace std;

class Outer
{
public:
    void display()
    {
        cout << "Display of Outer Class" << endl;
    }

    class Inner
    {
    public:
        void display()
        {
            cout << "Display of Inner Class" << endl;
        }
    };
};

int main()
{
    Outer o;
    Outer::Inner i;

    o.display();
    i.display();

    return 0;
}
