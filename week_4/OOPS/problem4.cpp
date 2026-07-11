#include <iostream>
using namespace std;

class Box
{
protected:
    int length, breadth;

public:
    Box(int l, int b)
    {
        length = l;
        breadth = b;
    }

    int area()
    {
        return length * breadth;
    }
};

class Box3D : public Box
{
private:
    int height;

public:
    Box3D(int l, int b, int h) : Box(l, b)
    {
        height = h;
    }

    int volume()
    {
        return length * breadth * height;
    }
};

int main()
{
    int l, b, h;

    cout << "Enter length breadth height: ";
    cin >> l >> b >> h;

    Box3D obj(l, b, h);

    cout << "Area = " << obj.area() << endl;
    cout << "Volume = " << obj.volume() << endl;

    return 0;
}
