#include <iostream>
using namespace std;

class Point
{
private:
    int x, y;

public:
    Point()
    {
        x = 0;
        y = 0;
    }

    Point(int a, int b)
    {
        x = a;
        y = b;
    }

    void setX(int a)
    {
        x = a;
    }

    void setY(int b)
    {
        y = b;
    }

    void setXY(int a, int b)
    {
        x = a;
        y = b;
    }

    void display()
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main()
{
    Point p1;
    Point p2(10, 20);

    p1.setXY(5, 8);

    p1.display();
    p2.display();

    return 0;
}
